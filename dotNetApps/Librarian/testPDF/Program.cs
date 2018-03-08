using System;
using System.Collections.Generic;
using System.Text;

using org.pdfbox.pdmodel;
using org.pdfbox.util;

namespace PDFReader
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = @"F:\etc\my.NETWork\Librarian\testPDF\data\changes.pdf";

            /* Load the PDF document. */
            PDDocument doc = PDDocument.load(path);

            /* Make a text reader for PDF. */
            PDFTextStripper pdfStripper = new PDFTextStripper();

            /* Write the text to the console. */
            Console.Write(pdfStripper.getText(doc));

            Console.Write("Done");
        }
    }
}
