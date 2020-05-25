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
    class asc126_generator
    {
        int TileHeight = 12;
        int TileWidth = 8;
        int NumberTileX;
        int NumberTileY;
        int TotalTiles;
        Bitmap img;
        public byte[] convertToByteArray(Bitmap b)
        {
            if (b.Width != 96 || b.Height != 132)
                throw new Exception("asc126.bmp deve essere da 96x132");

            img = b;
            NumberTileX = b.Width / TileWidth;
            NumberTileY = b.Height / TileHeight;
            TotalTiles = NumberTileX * NumberTileY;

            List<byte> bits = new List<byte>();
            for(int i=0;i<TotalTiles;i++)
            {
                bits.AddRange(GetTile(i));
            }

            return bits.ToArray();
        }

        private byte[] GetTile(int Index)
        {
            int x, y;
            x = Index % NumberTileX;
            y = Index / NumberTileX;
            x *= TileWidth;
            y *= TileHeight;
            byte[] bits = new byte[TileHeight]; //TileHeight*TileWidth/8

            int i = 0;
            for (int yy = y; yy < y + TileHeight; yy++)
            {
                byte row=0;
                for (int xx = x; xx < x + TileWidth; xx++)
                {
                    Color c = img.GetPixel(xx, yy);
                    byte b = (byte)(c.B != 0 || c.G != 0 || c.R != 0 ? 1 : 0);
                    row = (byte)(row << 1);
                    row = (byte)(row | b);
                }
                bits[i++] = row;
            }

            return bits;  

        }


    }
}
