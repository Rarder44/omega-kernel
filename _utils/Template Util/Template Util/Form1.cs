using ExtendCSharp;
using ExtendCSharp.ExtendedClass;
using ExtendCSharp.Forms;
using ExtendCSharp.Services;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using SM = ExtendCSharp.Services.ServicesManager;


namespace Template_Util
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            ServicesManager.RegistService(new SystemService());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FolderSelectDialog f = new FolderSelectDialog();
            if (f.ShowDialog())
            {
                textBox1.Text = f.FolderPath;
            }
        }

        async private void button2_Click(object sender, EventArgs e)
        {
            await Convert(textBox1.Text);
            label2.Text = "Done!";
        }

        String GritPath;
        String OutputFolderName = "theme";
        async public Task Convert(String Path)
        {
            SystemService ss = SM.Get<SystemService>();
            //creo la cartella Output
            String OutputFolder = ss.CombinePaths(Path, OutputFolderName);
            ss.CreateFolderSecure(OutputFolder);


            GritPath=ExtractGrit();
            //converto i file in .h ( sintassi normale )

            foreach(String File in ss.GetFiles(Path))
            {
                await GenerateH(File, OutputFolder);
            }
        


            //richiamo lo script della GRIT H to C per convertire il tutto
            GRIT_h_TO_c.ConvertClass.Convert(OutputFolder, (s) =>
             {
                 label2.SetTextInvoke(s);
             });

        }

        async private Task GenerateH(string FilePath,string OutputFolder)
        {
            SystemService ss = SM.Get<SystemService>();
            String FileName=ss.GetFileName(FilePath);
            String FileNameWE = ss.GetFileNameWithoutExtension(FilePath);
            if ( FileName=="asc126.bmp")
            {
                //file caratteri
                Bitmap b = new Bitmap(FilePath);
                asc126_generator g = new asc126_generator();
                byte[] bits=g.convertToByteArray(b);

                String outS = "const unsigned char ASC_DATA[] = {\r\n";
                for(int i=0;i<bits.Length;i++)
                {
                    outS+="0x"+bits[i].ToHexString(true)+", ";
                    if (i % 12 == 11)
                        outS += "\r\n";
                }
                outS += "};";
                String OutFile = ss.CombinePaths(OutputFolder, "asc126.h");
                ss.Write(OutFile, outS,false);

            }
            else if (FileName == "_text_palette.png")
            {
                //file caratteri
                Bitmap b = new Bitmap(FilePath);
                text_palette_generator tpg = new text_palette_generator();
                Dictionary<string, string> d = tpg.convert(b);


                String outS = "\r\n";
                foreach(KeyValuePair<String,String> kp in d)
                {
                    outS += "u16 " + kp.Key + " = " + kp.Value + ";\r\n";
                }

                String OutFile = ss.CombinePaths(OutputFolder, "_text_palette.h");
                ss.Write(OutFile, outS, false);

            }
            else if( FileName.EndsWith(".png"))     //TODO: implemento controlli per nomi corretti???
            {
                //file immagini

                //TODO: con grit vado a convertire il file
                ProcessPlus pp = new ProcessPlus(GritPath, "\""+FilePath+"\" -gB16 -gu8 -gb -ftc");
                pp.WorkingDirectory = OutputFolder;
                pp.CreateNoWindow = true;
                pp.Async = false;
                pp.WaitForExit = true;
                await pp.Start();

                string OutFileWithoutExtension = ss.CombinePaths(OutputFolder, ss.GetFileNameWithoutExtension(FileName));
                ss.DeleteSecure(OutFileWithoutExtension + ".h");                                 //tengo solo il .c 
                ss.Rename(OutFileWithoutExtension + ".c", OutFileWithoutExtension + ".h");       //lo converto in .h

                if (!ss.FileExist(OutFileWithoutExtension + ".h"))
                    return;

                String Cont = ss.Read(OutFileWithoutExtension + ".h");
                Cont = Cont.Replace(FileNameWE+"Bitmap", "gImage_"+ FileNameWE);
                ss.Write(OutFileWithoutExtension + ".h", Cont, false);
                //cambio il nome della variabile
            }   
            else
            {
                //file non convertibile
            }

        }

        /// <summary>
        /// Estrae Grit 
        /// Ritorna il Path dell'eseguibile
        /// </summary>
        /// <returns></returns>
        private String ExtractGrit()
        {
            ResourcesService rs = new ResourcesService(System.Reflection.Assembly.GetExecutingAssembly());
            SystemService ss = SM.Get<SystemService>();


            String TmpPath = ss.CombinePaths(Path.GetTempPath(), "grit");


            FilePlus fp = rs.GetObject<FilePlus>("Template_Util.GRIT.grit.exe");
            String GritPath = ss.CombinePaths(TmpPath, "grit.exe");
            fp.Folder = TmpPath;
            fp.Name = "grit";
            fp.Extension = ".exe";
            fp.Save();

            fp = rs.GetObject<FilePlus>("Template_Util.GRIT.FreeImage.dll");
            fp.Folder = TmpPath;
            fp.Name = "FreeImage";
            fp.Extension = ".dll";
            fp.Save();

            fp = rs.GetObject<FilePlus>("Template_Util.GRIT.licence-mit.txt");
            fp.Folder = TmpPath;
            fp.Name = "licence-mit";
            fp.Extension = ".txt";
            fp.Save();

            return GritPath;

        }
    }
}
