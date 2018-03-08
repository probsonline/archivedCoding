namespace SuperDirectoryCopy
{
    partial class SuperDirectyCopy
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
            this.cloneRadioButton = new System.Windows.Forms.RadioButton();
            this.treeCopyRadioButton = new System.Windows.Forms.RadioButton();
            this.oneLevelDownRadioButton = new System.Windows.Forms.RadioButton();
            this.zeroedRadioButton = new System.Windows.Forms.RadioButton();
            this.startButton = new System.Windows.Forms.Button();
            this.folderBrowser = new System.Windows.Forms.FolderBrowserDialog();
            this.closeButton = new System.Windows.Forms.Button();
            this.statusLabel = new System.Windows.Forms.Label();
            this.allFilesRadioButton = new System.Windows.Forms.RadioButton();
            this.UniqueFilesRadioButton = new System.Windows.Forms.RadioButton();
            this.FineControl_DeepestDelete = new System.Windows.Forms.CheckBox();
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
            this.sourcePathField.Text = "F:\\etc\\my.NETWork\\TestingArea\\ref";
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
            this.destPathField.Text = "F:\\etc\\my.NETWork\\TestingArea";
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
            // cloneRadioButton
            // 
            this.cloneRadioButton.AutoSize = true;
            this.cloneRadioButton.Location = new System.Drawing.Point(15, 128);
            this.cloneRadioButton.Name = "cloneRadioButton";
            this.cloneRadioButton.Size = new System.Drawing.Size(52, 17);
            this.cloneRadioButton.TabIndex = 3;
            this.cloneRadioButton.Text = "Clone";
            this.cloneRadioButton.UseVisualStyleBackColor = true;
            this.cloneRadioButton.CheckedChanged += new System.EventHandler(this.cloneRadioButton_CheckedChanged);
            // 
            // treeCopyRadioButton
            // 
            this.treeCopyRadioButton.AutoSize = true;
            this.treeCopyRadioButton.Location = new System.Drawing.Point(12, 151);
            this.treeCopyRadioButton.Name = "treeCopyRadioButton";
            this.treeCopyRadioButton.Size = new System.Drawing.Size(74, 17);
            this.treeCopyRadioButton.TabIndex = 3;
            this.treeCopyRadioButton.Text = "Tree Copy";
            this.treeCopyRadioButton.UseVisualStyleBackColor = true;
            this.treeCopyRadioButton.CheckedChanged += new System.EventHandler(this.treeCopyRadioButton_CheckedChanged);
            // 
            // oneLevelDownRadioButton
            // 
            this.oneLevelDownRadioButton.AutoSize = true;
            this.oneLevelDownRadioButton.Checked = true;
            this.oneLevelDownRadioButton.Location = new System.Drawing.Point(184, 151);
            this.oneLevelDownRadioButton.Name = "oneLevelDownRadioButton";
            this.oneLevelDownRadioButton.Size = new System.Drawing.Size(105, 17);
            this.oneLevelDownRadioButton.TabIndex = 3;
            this.oneLevelDownRadioButton.TabStop = true;
            this.oneLevelDownRadioButton.Text = "One Level Down";
            this.oneLevelDownRadioButton.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.oneLevelDownRadioButton.UseVisualStyleBackColor = true;
            this.oneLevelDownRadioButton.CheckedChanged += new System.EventHandler(this.oneLevelDownRadioButton_CheckedChanged);
            // 
            // zeroedRadioButton
            // 
            this.zeroedRadioButton.AutoSize = true;
            this.zeroedRadioButton.Location = new System.Drawing.Point(184, 128);
            this.zeroedRadioButton.Name = "zeroedRadioButton";
            this.zeroedRadioButton.Size = new System.Drawing.Size(57, 17);
            this.zeroedRadioButton.TabIndex = 3;
            this.zeroedRadioButton.Text = "zeroed";
            this.zeroedRadioButton.UseVisualStyleBackColor = true;
            this.zeroedRadioButton.CheckedChanged += new System.EventHandler(this.zeroedRadioButton_CheckedChanged);
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
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Location = new System.Drawing.Point(331, 173);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(0, 13);
            this.statusLabel.TabIndex = 8;
            // 
            // allFilesRadioButton
            // 
            this.allFilesRadioButton.AutoSize = true;
            this.allFilesRadioButton.Location = new System.Drawing.Point(101, 151);
            this.allFilesRadioButton.Name = "allFilesRadioButton";
            this.allFilesRadioButton.Size = new System.Drawing.Size(60, 17);
            this.allFilesRadioButton.TabIndex = 3;
            this.allFilesRadioButton.Text = "All Files";
            this.allFilesRadioButton.UseVisualStyleBackColor = true;
            this.allFilesRadioButton.CheckedChanged += new System.EventHandler(this.allFilesRadioButton_CheckedChanged);
            // 
            // UniqueFilesRadioButton
            // 
            this.UniqueFilesRadioButton.AutoSize = true;
            this.UniqueFilesRadioButton.Location = new System.Drawing.Point(101, 128);
            this.UniqueFilesRadioButton.Name = "UniqueFilesRadioButton";
            this.UniqueFilesRadioButton.Size = new System.Drawing.Size(77, 17);
            this.UniqueFilesRadioButton.TabIndex = 3;
            this.UniqueFilesRadioButton.Text = "Uniqe Files";
            this.UniqueFilesRadioButton.UseVisualStyleBackColor = true;
            // 
            // FineControl_DeepestDelete
            // 
            this.FineControl_DeepestDelete.AutoSize = true;
            this.FineControl_DeepestDelete.Location = new System.Drawing.Point(16, 186);
            this.FineControl_DeepestDelete.Name = "FineControl_DeepestDelete";
            this.FineControl_DeepestDelete.Size = new System.Drawing.Size(137, 17);
            this.FineControl_DeepestDelete.TabIndex = 9;
            this.FineControl_DeepestDelete.Text = "Delete Deepest Folders";
            this.FineControl_DeepestDelete.UseVisualStyleBackColor = true;
            this.FineControl_DeepestDelete.CheckedChanged += new System.EventHandler(this.FineControl_DeepestDelete_CheckedChanged);
            // 
            // SuperDirectyCopy
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(457, 231);
            this.Controls.Add(this.FineControl_DeepestDelete);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.zeroedRadioButton);
            this.Controls.Add(this.oneLevelDownRadioButton);
            this.Controls.Add(this.allFilesRadioButton);
            this.Controls.Add(this.UniqueFilesRadioButton);
            this.Controls.Add(this.treeCopyRadioButton);
            this.Controls.Add(this.cloneRadioButton);
            this.Controls.Add(this.DestBrowseButton);
            this.Controls.Add(this.destPathField);
            this.Controls.Add(this.sourceBrowseButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.sourcePathField);
            this.Controls.Add(this.label1);
            this.Name = "SuperDirectyCopy";
            this.Text = "Super Directory Copy";
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
        private System.Windows.Forms.RadioButton cloneRadioButton;
        private System.Windows.Forms.RadioButton treeCopyRadioButton;
        private System.Windows.Forms.RadioButton oneLevelDownRadioButton;
        private System.Windows.Forms.RadioButton zeroedRadioButton;
        private System.Windows.Forms.Button startButton;

        /* Manually added code. */
        private System.Windows.Forms.FolderBrowserDialog folderBrowser;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.RadioButton allFilesRadioButton;
        private System.Windows.Forms.RadioButton UniqueFilesRadioButton;
        private System.Windows.Forms.CheckBox FineControl_DeepestDelete;
    }
}

