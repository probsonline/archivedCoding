namespace PDFManager
{
    partial class PDFInfoManager
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
            this.readFileButton = new System.Windows.Forms.Button();
            this.fileInfoBox = new System.Windows.Forms.TextBox();
            this.filePathField = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.closeButton = new System.Windows.Forms.Button();
            this.fileListButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // readFileButton
            // 
            this.readFileButton.Location = new System.Drawing.Point(109, 54);
            this.readFileButton.Name = "readFileButton";
            this.readFileButton.Size = new System.Drawing.Size(81, 27);
            this.readFileButton.TabIndex = 0;
            this.readFileButton.Text = "Read PDF";
            this.readFileButton.UseVisualStyleBackColor = true;
            this.readFileButton.Click += new System.EventHandler(this.readPDFButton_Click);
            // 
            // fileInfoBox
            // 
            this.fileInfoBox.Location = new System.Drawing.Point(12, 93);
            this.fileInfoBox.Multiline = true;
            this.fileInfoBox.Name = "fileInfoBox";
            this.fileInfoBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.fileInfoBox.Size = new System.Drawing.Size(367, 318);
            this.fileInfoBox.TabIndex = 1;
            this.fileInfoBox.Text = "PDF Text will be displayed here";
            // 
            // filePathField
            // 
            this.filePathField.Location = new System.Drawing.Point(12, 24);
            this.filePathField.Name = "filePathField";
            this.filePathField.Size = new System.Drawing.Size(367, 20);
            this.filePathField.TabIndex = 2;
            this.filePathField.Text = "F:\\etc\\my.NETWork\\Librarian\\PDFManager\\data\\ESL.pdf";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "File Path";
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(205, 54);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(81, 27);
            this.clearButton.TabIndex = 0;
            this.clearButton.Text = "Clear Info Box";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // closeButton
            // 
            this.closeButton.Location = new System.Drawing.Point(298, 54);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(81, 27);
            this.closeButton.TabIndex = 4;
            this.closeButton.Text = "Close";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // fileListButton
            // 
            this.fileListButton.Enabled = false;
            this.fileListButton.Location = new System.Drawing.Point(10, 54);
            this.fileListButton.Name = "fileListButton";
            this.fileListButton.Size = new System.Drawing.Size(81, 27);
            this.fileListButton.TabIndex = 0;
            this.fileListButton.Text = "List Files";
            this.fileListButton.UseVisualStyleBackColor = true;
            // 
            // PDFInfoManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(391, 423);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.filePathField);
            this.Controls.Add(this.fileInfoBox);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.fileListButton);
            this.Controls.Add(this.readFileButton);
            this.Name = "PDFInfoManager";
            this.Text = "PDF Information Manager";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button readFileButton;
        private System.Windows.Forms.TextBox fileInfoBox;
        private System.Windows.Forms.TextBox filePathField;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.Button fileListButton;
    }
}

