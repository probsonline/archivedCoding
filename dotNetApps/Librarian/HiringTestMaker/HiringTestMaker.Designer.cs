namespace HiringTestMaker
{
    partial class HiringTestMaker
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
            this.createButton = new System.Windows.Forms.Button();
            this.connectButton = new System.Windows.Forms.Button();
            this.deleteButton = new System.Windows.Forms.Button();
            this.closeButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.genTestButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // createButton
            // 
            this.createButton.Location = new System.Drawing.Point(12, 12);
            this.createButton.Name = "createButton";
            this.createButton.Size = new System.Drawing.Size(132, 29);
            this.createButton.TabIndex = 0;
            this.createButton.Text = "Create Database";
            this.createButton.UseVisualStyleBackColor = true;
            this.createButton.Click += new System.EventHandler(this.createButton_Click);
            // 
            // connectButton
            // 
            this.connectButton.Location = new System.Drawing.Point(12, 47);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(132, 29);
            this.connectButton.TabIndex = 1;
            this.connectButton.Text = "Connect to Database";
            this.connectButton.UseVisualStyleBackColor = true;
            this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
            // 
            // deleteButton
            // 
            this.deleteButton.Location = new System.Drawing.Point(159, 12);
            this.deleteButton.Name = "deleteButton";
            this.deleteButton.Size = new System.Drawing.Size(132, 29);
            this.deleteButton.TabIndex = 2;
            this.deleteButton.Text = "Delete Database";
            this.deleteButton.UseVisualStyleBackColor = true;
            this.deleteButton.Click += new System.EventHandler(this.deleteButton_Click);
            // 
            // closeButton
            // 
            this.closeButton.Location = new System.Drawing.Point(159, 47);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(132, 29);
            this.closeButton.TabIndex = 3;
            this.closeButton.Text = "Close Database";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(12, 82);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(132, 29);
            this.addButton.TabIndex = 4;
            this.addButton.Text = "add Question";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // genTestButton
            // 
            this.genTestButton.Location = new System.Drawing.Point(159, 82);
            this.genTestButton.Name = "genTestButton";
            this.genTestButton.Size = new System.Drawing.Size(132, 29);
            this.genTestButton.TabIndex = 5;
            this.genTestButton.Text = "Generate Test";
            this.genTestButton.UseVisualStyleBackColor = true;
            this.genTestButton.Click += new System.EventHandler(this.genTestButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(106, 189);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(82, 30);
            this.exitButton.TabIndex = 6;
            this.exitButton.Text = "Close";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // HiringTestMaker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(627, 325);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.genTestButton);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.deleteButton);
            this.Controls.Add(this.connectButton);
            this.Controls.Add(this.createButton);
            this.Name = "HiringTestMaker";
            this.Text = "MW Test Generator";
            this.Load += new System.EventHandler(this.HiringTestMaker_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button createButton;
        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.Button deleteButton;
        private System.Windows.Forms.Button closeButton;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button genTestButton;
        private System.Windows.Forms.Button exitButton;
    }
}

