using ExtendCSharp.Services;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace GRIT_h_TO_c
{
    public static class ConvertClass
    {
        public static void Convert(String Path,Action<string> log)
        {
            String HeaderFileName = "IMAGES.h";
            String HeaderFilePath = "IMAGES.h";
            String HeaderDefine = "IMAGES_HEADER";

            SystemService ss = new SystemService();


            if (!ss.DirectoryExist(Path))           //controllo se la cartella esiste
            {
                log("Folder not exist");
                return;
            }
            HeaderFilePath = ss.CombinePaths(Path, HeaderFileName);

            String[] files = ss.GetFiles(Path);         //recupero la lista di file

            List<String> Headers = new List<string>();
            foreach (string file in files)               //per ciascun file
            {
                if (file.EndsWith(".h"))                //rinomino il file .h in .c
                {

                    string cont = ss.Read(file);            //recupero nel file la definizione dell'array
                    Regex r = new Regex("(const.*)=");
                    Match m = r.Match(cont);
                    if (m.Success)
                    {
                        Headers.Add("extern " + m.Groups[1].Value + ";");     //prendo solo la definizione e la metto da parte
                    }
                    //leggo il file 
                    ss.Write(file.Replace(".h", ".c"), "#include \"" + HeaderFileName + "\"\r\n" + cont, false);       //salvo il file c con l'include al .h

                    //cancello il file .h
                    ss.DeleteSecure(file);
                }
            }

            //creo il .h con tutti le dichiarazioni dei vettori extern
            ss.Write(HeaderFilePath, "#ifndef " + HeaderDefine + "\r\n#define " + HeaderDefine + "\r\n\r\n", false);

            foreach (string s in Headers)
            {
                ss.Write(HeaderFilePath, s + "\r\n", true);
            }

            ss.Write(HeaderFilePath, "#endif", true);
        }
    }
}
