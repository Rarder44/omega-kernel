using ExtendCSharp;
using ExtendCSharp.Forms;
using ExtendCSharp.Services;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace GRIT_h_TO_c
{
    public partial class Form1 : Form
    {
  
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FolderSelectDialog f = new FolderSelectDialog();
            if(f.ShowDialog())
            {
                textBox1.Text = f.FolderPath;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ConvertClass.Convert(textBox1.Text,(s)=> {
                label2.SetTextInvoke(s);
            });
        }


        
    }
}
