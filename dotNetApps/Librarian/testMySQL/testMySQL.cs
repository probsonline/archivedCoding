using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace testMySQL
{
    public partial class testMySQL : Form
    {
        public testMySQL()
        {
            InitializeComponent();
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            String dbPath = @"F:\etc\my.NETWork\Librarian\testMySQL\bin\Debug\PMP_DM_FILE.db";

//            DataDB myDB = new DataDB("localhost", "root", "kaleem", dbPath);
            DataDB myDB = new DataDB("localhost", "csharp", "csharp", "mp3collection");
            myDB.Connect();
        }
    }
}