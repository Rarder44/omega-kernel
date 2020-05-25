using ExtendCSharp.ExtendedClass;
using GongSolutions.Shell.Interop;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Template_Util
{
    class text_palette_generator
    {
        Bitmap img;
       

        public Dictionary<String, String> convert(Bitmap b)
        {
            Dictionary<int, String> paletteName = GRIT_h_TO_c.Text_Palette.GetPaletteNames;

            Dictionary<String, String> tmp = new Dictionary<String, String>();
            if (b.Width != 1 || b.Height != 10)
                throw new Exception("_text_palette.png deve essere da 1x10");

            for(int i=0;i<10;i++)
            {
                Color c = b.GetPixel(0, i);
                String NomePalette = paletteName[i];
                tmp[NomePalette] = "RGB(" + c.R/8 + "," + c.G/8 + "," + c.B/8 + ")";
            }


            return tmp;
        }

       


    }
}
