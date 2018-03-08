using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace PDFManager
{
    public partial class PDFInfoManager : Form
    {
        public PDFInfoManager()
        {
            InitializeComponent();
        }

        private void readPDFButton_Click(object sender, EventArgs e)
        {
            PDFInfoReader aPDF = new PDFInfoReader();

            fileInfoBox.Text = "reading";

            /* Open the PDF file. */
            aPDF.loadPDF(filePathField.Text);

            /* Get the PDF information and write to the text area. */
            fileInfoBox.Clear();
            fileInfoBox.WordWrap = true;
            fileInfoBox.AppendText("\r\nFile Name: " + aPDF.getFileName());
            fileInfoBox.AppendText("\r\nLocation: " + aPDF.getFileLocation());
            fileInfoBox.AppendText("\r\nFile Title: " + aPDF.getPDFTitle());
            fileInfoBox.AppendText("\r\n" + aPDF.getISBN());
            fileInfoBox.AppendText("\r\nAuthor: " + aPDF.getAuthor());

            fileInfoBox.AppendText("\r\n\r\n\r\n: testing\r\n");
            fileInfoBox.AppendText(aPDF.tempTest());


            /* Close the PDF file. */
            aPDF.unloadPDF();
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            fileInfoBox.Text = "PDF Text will be displayed here";

        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Close();
            this.Dispose();
        }
    }
}