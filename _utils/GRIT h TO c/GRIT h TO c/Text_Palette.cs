using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GRIT_h_TO_c
{
    public static class Text_Palette
    {
        public static Dictionary<int, String> GetPaletteNames
        {
            get
            {
                Dictionary<int, String> tmp = new Dictionary<int, String>();
                tmp.Add(0, "gl_color_selected");                     //posizioni in ordine (numerico) dei pixel nell'immagine
                tmp.Add(1, "gl_color_text");
                tmp.Add(2, "gl_color_selectBG_sd");
                tmp.Add(3, "gl_color_selectBG_nor");
                tmp.Add(4, "gl_color_MENU_btn");
                tmp.Add(5, "gl_color_cheat_count");
                tmp.Add(6, "gl_color_cheat_black");
                tmp.Add(7, "gl_color_NORFULL");
                tmp.Add(8, "gl_color_btn_clean");
                tmp.Add(9, "gl_color_patch_note");
                return tmp;
            }
        }

    }
}
