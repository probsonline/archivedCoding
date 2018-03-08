namespace FileLister
{
    partial class FileLister
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.sourcePathField = new System.Windows.Forms.TextBox();
            this.sourceBrowseButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.destPathField = new System.Windows.Forms.TextBox();
            this.DestBrowseButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.startButton = new System.Windows.Forms.Button();
            this.folderBrowser = new System.Windows.Forms.FolderBrowserDialog();
            this.closeButton = new System.Windows.Forms.Button();
            this.NewListing = new System.Windows.Forms.RadioButton();
            this.AppendListing = new System.Windows.Forms.RadioButton();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.rbEmptyDirs = new System.Windows.Forms.RadioButton();
            this.cbDelEmpty = new System.Windows.Forms.CheckBox();
            this.rbMultiPartFile = new System.Windows.Forms.RadioButton();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.bdelItem = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(13, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Source";
            // 
            // sourcePathField
            // 
            this.sourcePathField.Location = new System.Drawing.Point(12, 36);
            this.sourcePathField.Name = "sourcePathField";
            this.sourcePathField.Size = new System.Drawing.Size(354, 20);
            this.sourcePathField.TabIndex = 1;
            this.sourcePathField.Text = "G:\\ReferenceLiterature";
            // 
            // sourceBrowseButton
            // 
            this.sourceBrowseButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.sourceBrowseButton.Location = new System.Drawing.Point(372, 36);
            this.sourceBrowseButton.Name = "sourceBrowseButton";
            this.sourceBrowseButton.Size = new System.Drawing.Size(77, 20);
            this.sourceBrowseButton.TabIndex = 2;
            this.sourceBrowseButton.Text = "Browse";
            this.sourceBrowseButton.UseVisualStyleBackColor = true;
            this.sourceBrowseButton.Click += new System.EventHandler(this.sourceBrowseButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(13, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 13);
            this.label2.TabIndex = 0;
            this.label2.Text = "Destination";
            // 
            // destPathField
            // 
            this.destPathField.Location = new System.Drawing.Point(12, 80);
            this.destPathField.Name = "destPathField";
            this.destPathField.Size = new System.Drawing.Size(354, 20);
            this.destPathField.TabIndex = 1;
            this.destPathField.Text = "G:\\";
            // 
            // DestBrowseButton
            // 
            this.DestBrowseButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.DestBrowseButton.Location = new System.Drawing.Point(372, 80);
            this.DestBrowseButton.Name = "DestBrowseButton";
            this.DestBrowseButton.Size = new System.Drawing.Size(77, 20);
            this.DestBrowseButton.TabIndex = 2;
            this.DestBrowseButton.Text = "Browse";
            this.DestBrowseButton.UseVisualStyleBackColor = true;
            this.DestBrowseButton.Click += new System.EventHandler(this.DestBrowseButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(13, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 13);
            this.label3.TabIndex = 0;
            this.label3.Text = "Options";
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(372, 118);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(77, 23);
            this.startButton.TabIndex = 5;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // closeButton
            // 
            this.closeButton.Location = new System.Drawing.Point(372, 151);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(77, 23);
            this.closeButton.TabIndex = 7;
            this.closeButton.Text = "Close";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // NewListing
            // 
            this.NewListing.AutoSize = true;
            this.NewListing.Location = new System.Drawing.Point(155, 128);
            this.NewListing.Name = "NewListing";
            this.NewListing.Size = new System.Drawing.Size(113, 17);
            this.NewListing.TabIndex = 3;
            this.NewListing.Text = "Append to Existing";
            this.NewListing.UseVisualStyleBackColor = true;
            this.NewListing.CheckedChanged += new System.EventHandler(this.AppendListing_CheckedChanged);
            // 
            // AppendListing
            // 
            this.AppendListing.AutoSize = true;
            this.AppendListing.Location = new System.Drawing.Point(15, 128);
            this.AppendListing.Name = "AppendListing";
            this.AppendListing.Size = new System.Drawing.Size(114, 17);
            this.AppendListing.TabIndex = 3;
            this.AppendListing.Text = "Create New Listing";
            this.AppendListing.UseVisualStyleBackColor = true;
            this.AppendListing.CheckedChanged += new System.EventHandler(this.NewListingRadioButton_CheckedChanged);
            // 
            // rbEmptyDirs
            // 
            this.rbEmptyDirs.AutoSize = true;
            this.rbEmptyDirs.Location = new System.Drawing.Point(16, 153);
            this.rbEmptyDirs.Name = "rbEmptyDirs";
            this.rbEmptyDirs.Size = new System.Drawing.Size(126, 17);
            this.rbEmptyDirs.TabIndex = 8;
            this.rbEmptyDirs.Text = "List Empty Directories";
            this.rbEmptyDirs.UseVisualStyleBackColor = true;
            this.rbEmptyDirs.CheckedChanged += new System.EventHandler(this.rbEmptyDirs_CheckedChanged);
            // 
            // cbDelEmpty
            // 
            this.cbDelEmpty.AutoSize = true;
            this.cbDelEmpty.Location = new System.Drawing.Point(155, 153);
            this.cbDelEmpty.Name = "cbDelEmpty";
            this.cbDelEmpty.Size = new System.Drawing.Size(86, 17);
            this.cbDelEmpty.TabIndex = 9;
            this.cbDelEmpty.Text = "DeleteEmpty";
            this.cbDelEmpty.UseVisualStyleBackColor = true;
            this.cbDelEmpty.CheckedChanged += new System.EventHandler(this.cbDelEmpty_CheckedChanged);
            // 
            // rbMultiPartFile
            // 
            this.rbMultiPartFile.AutoSize = true;
            this.rbMultiPartFile.Checked = true;
            this.rbMultiPartFile.Location = new System.Drawing.Point(16, 176);
            this.rbMultiPartFile.Name = "rbMultiPartFile";
            this.rbMultiPartFile.Size = new System.Drawing.Size(112, 17);
            this.rbMultiPartFile.TabIndex = 10;
            this.rbMultiPartFile.TabStop = true;
            this.rbMultiPartFile.Text = "List Multi Part Files";
            this.rbMultiPartFile.UseVisualStyleBackColor = true;
            this.rbMultiPartFile.CheckedChanged += new System.EventHandler(this.rbMultiPartFile_CheckedChanged);
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.CheckOnClick = true;
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(12, 200);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(437, 409);
            this.checkedListBox1.TabIndex = 11;
            this.checkedListBox1.ThreeDCheckBoxes = true;
            this.checkedListBox1.SelectedIndexChanged += new System.EventHandler(this.checkedListBox1_SelectedIndexChanged);
            // 
            // bdelItem
            // 
            this.bdelItem.Location = new System.Drawing.Point(155, 176);
            this.bdelItem.Name = "bdelItem";
            this.bdelItem.Size = new System.Drawing.Size(111, 23);
            this.bdelItem.TabIndex = 12;
            this.bdelItem.Text = "Save Selected";
            this.bdelItem.UseVisualStyleBackColor = true;
            this.bdelItem.Click += new System.EventHandler(this.bdelItem_Click);
            // 
            // FileLister
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(465, 624);
            this.Controls.Add(this.bdelItem);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.rbMultiPartFile);
            this.Controls.Add(this.cbDelEmpty);
            this.Controls.Add(this.rbEmptyDirs);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.NewListing);
            this.Controls.Add(this.AppendListing);
            this.Controls.Add(this.DestBrowseButton);
            this.Controls.Add(this.destPathField);
            this.Controls.Add(this.sourceBrowseButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.sourcePathField);
            this.Controls.Add(this.label1);
            this.Name = "FileLister";
            this.Text = "File Lister";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox sourcePathField;
        private System.Windows.Forms.Button sourceBrowseButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox destPathField;
        private System.Windows.Forms.Button DestBrowseButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button startButton;

        /* Manually added code. */
        private System.Windows.Forms.FolderBrowserDialog folderBrowser;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.RadioButton NewListing;
        private System.Windows.Forms.RadioButton AppendListing;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.RadioButton rbEmptyDirs;
        private System.Windows.Forms.CheckBox cbDelEmpty;
        private System.Windows.Forms.RadioButton rbMultiPartFile;
        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.Button bdelItem;
    }
}

