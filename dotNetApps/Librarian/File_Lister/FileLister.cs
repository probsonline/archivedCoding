using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace FileLister
{
    public partial class FileLister : Form
    {
        /* Constants to identify various copy operation types. */
        const int CREATE_NEW_LISTING = 0;
        const int APPEND_TO_LISTING = 1;
        const int EMPTY_DIRECTORY = 2;
        const int MULTI_PART_FILE = 3;

        Boolean DeleteEmpty = false;

        private int Save_File_List = CREATE_NEW_LISTING;

        String sourcePath = null;
        String destPath = null;

        public FileLister()
        {
            InitializeComponent();
        }

        /* Event Handlers for buttons. */
        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }
        
        private void startButton_Click(object sender, EventArgs e)
        {
            /* Get the source path. */
            sourcePath = this.sourcePathField.Text;

            /* Get the destination path. */
            destPath = this.destPathField.Text;

            /* Get the source directory. */
            DirectoryInfo sourceDirectory = new DirectoryInfo(@sourcePath);

            /* Get destination directory. */
            DirectoryInfo destDirectory = new DirectoryInfo(@destPath);

            /* Check if the source directory exists. */
            if (sourceDirectory.Exists == false)
            {
                MessageBox.Show("Source path invalid. Please specify the correct source path. Use Browse button for clarity.");
            }

            /* Check if the destination directory exists. */
            else if (destDirectory.Exists == false)
            {
                MessageBox.Show("Destination path invalid. Please specify the correct source path. Use Browse button for clarity.");
            }
            else
            {
                saveFileListing(sourceDirectory, destDirectory);

                MessageBox.Show("Done");
            }
        }

        private void sourceBrowseButton_Click(object sender, EventArgs e)
        {
            /* Start the folder browse dialog with the selected path. */
            this.folderBrowser.SelectedPath = this.sourcePathField.Text;

            /* Show the dialog box. */
            this.folderBrowser.ShowDialog();

            /* Update the source path with the newly browsed path. */
            this.sourcePathField.Text = this.folderBrowser.SelectedPath;
        }

        private void DestBrowseButton_Click(object sender, EventArgs e)
        {
            /* Start the folder browse dialog with the selected path. */
            this.folderBrowser.SelectedPath = this.destPathField.Text;

            /* Show the dialog box. */
            this.folderBrowser.ShowDialog();

            /* Update the source path with the newly browsed path. */
            this.destPathField.Text = this.folderBrowser.SelectedPath;
        }

        private void saveFileListing(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get the complete path for the file where listing will be save. */
            String listingFile = Path.Combine(dDir.FullName, "fileListing.text");

            /* Create a file for saving file listing. */
            try
            {
                switch (Save_File_List)
                {
                    //Create file listing in a text file.
                    case CREATE_NEW_LISTING:
                        /* Create new/overwrite the existing file. */
                        using (StreamWriter fileWriter = new StreamWriter(listingFile, false))
                        {
                            /* Get each file's name and save to the file. */
                            saveFileName(sDir, fileWriter);

                            fileWriter.Close();
                        }

                        break;

                    //Append to the already created file listing.
                    case APPEND_TO_LISTING:
                        using (StreamWriter fileWriter = new StreamWriter(listingFile, true))
                        {
                            /* Get each file's name and save to the file. */
                            saveFileName(sDir, fileWriter);

                            fileWriter.Close();
                        }
                        break;

                    //List only the directories that are empty.
                    case EMPTY_DIRECTORY:
                        listingFile = Path.Combine(dDir.FullName, "emptyDirs.text");

                        /* Create new/overwrite the existing file. */
                        using (StreamWriter fileWriter = new StreamWriter(listingFile, false))
                        {
                            /* Get each file's name and save to the file. */
                            saveEmptyDirs(sDir, fileWriter);

                            fileWriter.Close();
                        }

                        break;

                    //List the folders that contain multiple files for a single file e.g. chapters of a book
                    case MULTI_PART_FILE:
                        listingFile = Path.Combine(dDir.FullName, "multiFileBook.text");

                        /* Create new/overwrite the existing file. */
                        using (StreamWriter fileWriter = new StreamWriter(listingFile, false))
                        {
                            /* Get each file's name and save to the file. */
                            saveMultiFileBook(sDir, fileWriter);

                            fileWriter.Close();
                        }
                        break;
                    default:
                        break;
                }
            }
            catch (System.Exception e)
            {
                Console.WriteLine("File couldn't be created at destination" + e.ToString());
            }
        }
        
        private void saveFileName(DirectoryInfo sDir, StreamWriter fileWriter)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Write each files name in the listing file. */
            /* Get each file's name and save to the file. */
            foreach (FileInfo aFile in sourceRootFiles)
            {
                fileWriter.WriteLine(aFile.Name);
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                fileWriter.WriteLine("\n=======================================");
                fileWriter.WriteLine(nextSourceSubDir.FullName);
                fileWriter.WriteLine("=======================================");

                /* Recursively call this function to copy to the deepest level. */
                saveFileName(nextSourceSubDir, fileWriter);
            }
        }

        private void saveEmptyDirs(DirectoryInfo sDir, StreamWriter fileWriter)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Check if there are no files or directories in the directory. */
            if ((sourceRootFiles.Length == 0) && (sourceSubDirs.Length == 0))
            {
                /* Save the empty directory name. */
                fileWriter.WriteLine(sDir.FullName);

                if (DeleteEmpty == true)
                {
                    try
                    {
                        sDir.Delete();
                    }
                    catch (System.Exception e){
                        Console.WriteLine(e.ToString());
                    }
                }

            }
            else
            {
                /* Copy all the directories and their files recursively to the destination. */
                foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
                {
                    /* Recursively call this function to copy to the deepest level. */
                    saveEmptyDirs(nextSourceSubDir, fileWriter);
                }
            }
        }

        private void saveMultiFileBook(DirectoryInfo sDir, StreamWriter fileWriter)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Check if this directory contains no sub-folders. */
            if (sourceSubDirs.Length == 0)
            {
                /* Write directory path and the files in it to file. */
                fileWriter.WriteLine(sDir.FullName);
                addDirInList(sDir.FullName);
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                /* Recursively call this function to copy to the deepest level. */
                saveMultiFileBook(nextSourceSubDir, fileWriter);
            }
        }

        private void addDirInList(String file)
        {
            checkedListBox1.Items.Add(file);
        }

        private void NewListingRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;

            if (rb.Checked == true)
            {
                /* Set the option to create new file listing. */
                Save_File_List = CREATE_NEW_LISTING;
            }
        }

        private void AppendListing_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;

            if (rb.Checked == true)
            {
                /* Set the option to create new file listing. */
                Save_File_List = APPEND_TO_LISTING;
            }

        }

        private void rbEmptyDirs_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;

            if (rb.Checked == true)
            {
                /* Set the option to create new file listing. */
                Save_File_List = EMPTY_DIRECTORY;
            }

        }

        private void rbMultiPartFile_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;

            if (rb.Checked == true)
            {
                /* Set the option to create new file listing. */
                Save_File_List = MULTI_PART_FILE;
            }
        }

        private void cbDelEmpty_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox cb = (CheckBox)sender;

            if (cb.Checked)
            {
                DeleteEmpty = true;
            }
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            CheckedListBox clb = (CheckedListBox)sender;

            if (clb.GetItemChecked(clb.SelectedIndex))
            {
                System.Diagnostics.Process.Start(clb.SelectedItem.ToString());
            }
        }

        private void bdelItem_Click(object sender, EventArgs e)
        {
            /* Get the complete path for the file where listing will be save. */
            String listingFile = Path.Combine("G:\\", "multiPartBok.text");

            /* Create new/overwrite the existing file. */
            using (StreamWriter fileWriter = new StreamWriter(listingFile, false))
            {
                foreach (int itemx in checkedListBox1.SelectedIndices)
                {
                    //    checkedListBox1.Items.RemoveAt(itemx);
                    fileWriter.WriteLine("Kaleem");
                }

                fileWriter.Close();
            }

        }
    }
}
