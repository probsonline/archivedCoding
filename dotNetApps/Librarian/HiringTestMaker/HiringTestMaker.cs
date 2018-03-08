using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using MySql.Data.MySqlClient;

namespace HiringTestMaker
{
    public partial class HiringTestMaker : Form
    {
        MySqlConnection testDB;
        String dbCmd;
        const String dbName = "MWTest";

        public HiringTestMaker()
        {
            InitializeComponent();
        }

        private void HiringTestMaker_Load(object sender, EventArgs e)
        {
            this.CenterToScreen();
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            
            testDB = new MySqlConnection("Data Source=localhost;" +
                                     "Persist Security Info=yes;" +
                                     "UserId=root; PWD=yes;");
            new MySqlConnection()

            dbCmd = "CREATE DATABASE " + dbName + ";";
            MySqlCommand dbCommand = new MySqlCommand(dbCmd, testDB);

            testDB.Open();
            dbCommand.ExecuteNonQuery();
        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            testDB.Open();
            
            

//            DataDB myDB = new DataDB("localhost", "csharp", "csharp", "mp3collection");
//            myDB.Connect();
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            testDB.Close();
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            dbCmd = "DROP DATABSE " + dbName + "; ";
            MySqlCommand dbCommand = new MySqlCommand(dbCmd, testDB);
        }

        private void genTestButton_Click(object sender, EventArgs e)
        {

        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
            this.Dispose();
        }

        private void addButton_Click(object sender, EventArgs e)
        {

        }
    }
}