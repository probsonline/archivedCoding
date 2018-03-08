using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

using org.pdfbox.pdmodel;
using org.pdfbox.util;

using org.pdfbox.searchengine.lucene;

namespace PDFManager
{
    class PDFInfoReader
    {

#region file operations
        public void loadPDF(String pdfFilePath)
        {
            //Get the file path
            filePath = @pdfFilePath;

            /* Load the PDF document. */
            pdfDoc = PDDocument.load(filePath);

            /* Make a text reader for PDF. */
            pdfInfoGetter = new PDFTextStripper();

            pdfInfoGetter.setEndPage(LastPage);

            pdfText = pdfInfoGetter.getText(pdfDoc);

        }

        public void unloadPDF()
        {
            pdfDoc.close();
        }
#endregion

#region pdf information

        public String getFileName()
        {
            FilesManager fm = new FilesManager("");
            return (fm.getFileName(filePath));
        }

        public String getFileLocation()
        {
            FilesManager fm = new FilesManager("");
            return (fm.getFilePath(filePath));
        }

        public String getISBN()
        {
            String info;
            info = pdfText.Substring(pdfText.IndexOf("ISBN", StringComparison.OrdinalIgnoreCase), 30);
            return info;
        }

        public String getPDFTitle()
        {
            String info = pdfDoc.getDocumentInformation().getTitle();

            if (((info.Equals(getFileName(), StringComparison.OrdinalIgnoreCase)) || info.Equals("") || (info == null)))
            {
                pdfInfoGetter.setEndPage(2);
                /* Re-read the second page only for title. Leave the previously read stream unaffected. */
                info = pdfInfoGetter.getText(pdfDoc);
                info = info.Trim();
                info = info.Substring(0, ((info.Length < 256) ? (info.Length - 1) : 256));
            }

            return info;
        }

        public String getAuthor()
        {
            String info = pdfDoc.getDocumentInformation().getAuthor();

            return info;
        }

        public String tempTest()
        {
            String info = "";


            info = pdfDoc.getDocumentInformation().getCreationDate().toString();
            
            PDPage apage = new PDPage();
            apage.getMetadata();

            return info;
        }

#endregion

        String filePath;
        PDDocument pdfDoc;
        PDFTextStripper pdfInfoGetter;
        String pdfText;
        const int LastPage = 6;

    }
}
