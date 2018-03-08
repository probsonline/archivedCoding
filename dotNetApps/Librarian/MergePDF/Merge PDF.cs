using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using org.pdfbox.pdmodel;
using org.pdfbox.util;

namespace MergePDF
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void bMerge_Click(object sender, EventArgs e)
        {
            mergePDF(@"F:\etc\my.NETWork\Librarian\MergePDF\data");
        }

        private void mergePDF(string folderPath)
        {
            String path = @folderPath;
            String outputFile = @folderPath + "\\output.pdf";
            /* Get first PDF. */
            //PDDocument pdf1 = PDDocument.load(path + "\\Input1.pdf");

            /* Get second PDF. */
            //PDDocument pdf2 = PDDocument.load(path + "\\input2.pdf");



        }
    }
}
