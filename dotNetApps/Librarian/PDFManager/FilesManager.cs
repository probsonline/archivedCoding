using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace PDFManager
{
    class FilesManager
    {
        String FileManagerName;

        public FilesManager(String name){
            this.FileManagerName = name;
        }

        public String getFileName(String fullPath)
        {
            FileInfo file = new FileInfo(@fullPath);

            return (file.Name);
        }

        public String getFilePath(String fullPath)
        {
            FileInfo file = new FileInfo(@fullPath);

            return (file.DirectoryName);
        }
    }
}
