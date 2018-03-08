using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace SuperDirectoryCopy
{
    public partial class SuperDirectyCopy : Form
    {
        /* Constants to identify various copy operation types. */
        const int NONE = 0;
        const int CLONE = 1;
        const int TREE = 2;
        const int FILES_ONLY = 3;
        const int ZEROED = 4;
        const int ONE_LEVEL_DOWN = 5;
        const int ALL_FILES_DUPLICATE_ALLOWED = 6;


        String sourcePath = null;
        String destPath = null;
        static int copyOption = ONE_LEVEL_DOWN;
        static Boolean DeleteDeepest = false;

        public SuperDirectyCopy()
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
                /* Check which operation to perform. */
                switch (copyOption)
                {
                case CLONE:
                    /* Copy all source to destination. */
                    cloneCopy(sourceDirectory, destDirectory);
                    break;
                case TREE:
                    /* Copy all source directory structure to destination. */
                    treeCopy(sourceDirectory, destDirectory);
                    break;
                case FILES_ONLY:
                    /* Copy all source files to destination. */
                    plainFilesCopy(sourceDirectory, destDirectory);
                    break;

                case ALL_FILES_DUPLICATE_ALLOWED:
                    noLossPlainFilesCopy(sourceDirectory, destDirectory);
                    break;
                case ZEROED:
                    /* Copy all source files to destination with zero size. */
                    zeroedCopy(sourceDirectory, destDirectory);
                    break;
                case ONE_LEVEL_DOWN:
                    /* Copy all the contents of each subfolder in the source to the destination. */
                    oneLevelDownCopy(sourceDirectory, destDirectory);
                    break;
                case NONE:
                default:
                    /* No operation to perform. */
                    break;
                }

                String statusMessage = "Copied";

                if(DeleteDeepest == true)
                {
                    statusMessage += ". Now performing fine control operations as specified.";
                }

                MessageBox.Show(statusMessage, "Operation Status");

                if (DeleteDeepest ==  true)
                {
                    makeBackup(destDirectory); //Make a backup for comparison.
                    DeleteDeepestFolder(destDirectory);
                }

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

        private void cloneRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;

            if (rb.Checked == true)
            {
                /* Set copy option to cloning all the tree with files. */
                copyOption = CLONE;
            }
        }

        private void treeCopyRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            /* Set the option to copy only the empty tree structure. */
            copyOption = TREE;
        }

        private void UniqueFilesRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            /* Set the option to copy only files from all directories. */
            copyOption = FILES_ONLY;
        }

        private void allFilesRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            copyOption = ALL_FILES_DUPLICATE_ALLOWED;
        }

        private void oneLevelDownRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            /* Set the option to all the folder names and file names. The files will however have zero size. */
            copyOption = ONE_LEVEL_DOWN;
        }

        private void zeroedRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            /* Set the option to copy the tree from each folder in the source to the destination. */
            copyOption = ZEROED;
        }

        private void FineControl_DeepestDelete_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox source = (CheckBox)sender;

            if (source.Checked)
            {
                DeleteDeepest = true;
            }
            else
            {
                DeleteDeepest = false;
            }
        }

        /* Logic for the operations. */
        private void cloneCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        { 
            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* First copy all the files to the destination. */
            foreach (FileInfo aFile in sourceRootFiles)
            {
                /* Copy the file the destination overwriting any existing ones. */
                aFile.CopyTo(Path.Combine(dDir.ToString(), aFile.Name), true);
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                try
                {
                    /* Create the folder at the destination. */
                    DirectoryInfo nextTargetSubDir = dDir.CreateSubdirectory(nextSourceSubDir.Name);

                    /* Recursively call this function to copy to the deepest level. */
                    cloneCopy(nextSourceSubDir, nextTargetSubDir);
                }
                catch (Exception e)
                {
                    Console.WriteLine("The process failed: {0}", e.ToString());
                }
            }
        }

        /* Logic for the operations. */
        private void treeCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                try
                {
                    /* Create the folder at the destination. */
                    DirectoryInfo nextTargetSubDir = dDir.CreateSubdirectory(nextSourceSubDir.Name);

                    /* Recursively call this function to copy to the deepest level. */
                    treeCopy(nextSourceSubDir, nextTargetSubDir);
                }
                catch (Exception e)
                {
                    Console.WriteLine("The process failed: {0}", e.ToString());                	
                }
            }
        }

        /* Logic for the operations. */
        private void plainFilesCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* First copy all the files to the destination. */
            foreach (FileInfo aFile in sourceRootFiles)
            {
                String emptyFileFullName = Path.Combine(dDir.FullName, aFile.Name);

                /* Copy the file the destination overwriting any existing ones. */
                aFile.CopyTo(emptyFileFullName, true);
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                /* Recursively call this function to copy to the deepest level. */
                plainFilesCopy(nextSourceSubDir, dDir);
            }
        }

        /* Logic for the operations. */
        private void noLossPlainFilesCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* First copy all the files to the destination. */
            foreach (FileInfo aFile in sourceRootFiles)
            {
                String emptyFileFullName = Path.Combine(dDir.FullName, aFile.Name);

                copySingleFile(aFile, emptyFileFullName);
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                /* Recursively call this function to copy to the deepest level. */
                noLossPlainFilesCopy(nextSourceSubDir, dDir);
            }
        }

        int sameNameFileCounter;
        void copySingleFile(FileInfo aFile, String destFileFullName)
        {
            try
            {
                if (File.Exists(destFileFullName) == false)
                {
                    /* Copy the file the destination overwriting any existing ones. */
                    aFile.CopyTo(destFileFullName, false);

                    sameNameFileCounter = 0;
                }
                else
                {
//                    copySingleFile(aFile, String.Concat(destFileFullName + sameNameFileCounter.ToString()));
                    //copySingleFile(aFile, String.Concat(destFileFullName.Substring(0, destFileFullName.Length-sameNameFileCounter.ToString().Length) + sameNameFileCounter.ToString()));
                    sameNameFileCounter++;

                    if (sameNameFileCounter > 1) 
                    {
//                        copySingleFile(aFile, String.Concat(destFileFullName.Substring(0, (destFileFullName.Length-1)) + sameNameFileCounter));
                        copySingleFile(aFile, String.Concat(destFileFullName + sameNameFileCounter.ToString()));
                    }
                    else
                    {
                        copySingleFile(aFile, String.Concat(destFileFullName + sameNameFileCounter));
                    }
                }
            }
            catch (System.Exception e)
            {
                Console.WriteLine("Operation failed during all file copying");
            	
            }
        }

        /* Logic for the operations. */
        private void zeroedCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get all the files at the root of the source directory i.e. which are not in a sub folder. */
            FileInfo[] sourceRootFiles = sDir.GetFiles();

            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* First copy all the files to the destination. */
            foreach (FileInfo aFile in sourceRootFiles)
            {
                /* Get the complete path for the destination empty file with the 
                 * same name as the source file. */
                String destEmptyFile = Path.Combine(dDir.FullName, aFile.Name);

                try
                {
                    /* Create the File. */
                    File.Create(destEmptyFile);
                }
                catch (System.Exception e)
                {
                    Console.WriteLine("Empty file couldn't be created at destination");
                }
            }

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                try
                {
                    /* Create the folder at the destination. */
                    DirectoryInfo nextTargetSubDir = dDir.CreateSubdirectory(nextSourceSubDir.Name);

                    /* Recursively call this function to copy to the deepest level. */
                    zeroedCopy(nextSourceSubDir, nextTargetSubDir);
                }
                catch (Exception e)
                {
                    Console.WriteLine("The process failed: {0}", e.ToString());                	
                }
            }
        }

        /* Logic for the operations. */
        private void oneLevelDownCopy(DirectoryInfo sDir, DirectoryInfo dDir)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = sDir.GetDirectories();

            /* Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                cloneCopy(nextSourceSubDir, dDir);
            }
        }

        /* Logic for the operations. */
        private void DeleteDeepestFolder(DirectoryInfo dir)
        {
            /* Get all the sub folders in the source directory. */
            DirectoryInfo[] sourceSubDirs = dir.GetDirectories();

            /* Delete the deepest folder in each folder. Copy all the directories and their files recursively to the destination. */
            foreach (DirectoryInfo nextSourceSubDir in sourceSubDirs)
            {
                try
                {
//                    if (isAllowedRoot(nextSourceSubDir) == false)
                    if (nextSourceSubDir.GetDirectories().Length == 0) // Check if this directory contains no further directories.
                    {
                        nextSourceSubDir.Delete();
                    }
                    else
                    {
                        DeleteDeepestFolder(nextSourceSubDir);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("The process failed: {0}", e.ToString());
                }
            }
        }

        private Boolean isAllowedRoot(DirectoryInfo dirToCheck)
        {
            Boolean isRoot = false;

            if (dirToCheck.Name.Equals("ce") ||
                dirToCheck.Name.Equals("cs") ||
                dirToCheck.Name.Equals("ee") ||
                dirToCheck.Name.Equals("Embedded") ||
                dirToCheck.Name.Equals("Engineering") ||
                dirToCheck.Name.Equals("erratas") ||
                dirToCheck.Name.Equals("Hobbyist&TechnicianLevel") ||
                dirToCheck.Name.Equals("linguistics") ||
                dirToCheck.Name.Equals("Medical") ||
                dirToCheck.Name.Equals("non-Science") ||
                dirToCheck.Name.Equals("OperatingSystems") ||
                dirToCheck.Name.Equals("Science") ||
                dirToCheck.Name.Equals("solutionmanual") ||
                dirToCheck.Name.Equals("SpecialTopics")
                )
            {
                isRoot = true;
            }

            return isRoot;
        }

        private void makeBackup(DirectoryInfo dir)
        {
            DirectoryInfo backDir;

            try
            {
                backDir = new DirectoryInfo(dir.FullName + ".back");

                cloneCopy(dir, backDir);
            }
            catch (System.Exception e)
            {
                Console.Write(e.ToString());
            }

        }
    }
}