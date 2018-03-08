namespace MergePDF
{
    partial class FormMain
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
            this.bMerge = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // bMerge
            // 
            this.bMerge.Location = new System.Drawing.Point(33, 20);
            this.bMerge.Name = "bMerge";
            this.bMerge.Size = new System.Drawing.Size(183, 38);
            this.bMerge.TabIndex = 0;
            this.bMerge.Text = "Merge";
            this.bMerge.UseVisualStyleBackColor = true;
            this.bMerge.Click += new System.EventHandler(this.bMerge_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(249, 78);
            this.Controls.Add(this.bMerge);
            this.Name = "FormMain";
            this.Text = "Merge PDF";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button bMerge;
    }
}

