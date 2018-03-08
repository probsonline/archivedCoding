using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

using MySql.Data.MySqlClient;

namespace testMySQL
{
    class DataDB
    {
        string Server;
        string Username;
        string Password;
        string Database;

/*
* Default Constructor for the class.
* It will be passed 4 items of data. 4 strings with
* connection information, and a windows forms label
* to show the connection status */
#region Default Constructor
        public DataDB(String myServer, string myUserName, string myPassword, string myDatabase)
        {
            try
            {
                this.Server = myServer;
                this.Username = myUserName;
                this.Password = myPassword;
                this.Database = myDatabase;

                // Check to make sure that our class was passed information
                // from the caller before we attempt to connect
                if (String.IsNullOrEmpty(Server))
                throw new InvalidDataException("No Server Specified");
                if (String.IsNullOrEmpty(Username))
                throw new InvalidDataException("No Username Specified");
                if (String.IsNullOrEmpty(Password))
                throw new InvalidDataException("No Password Specified");
                if (String.IsNullOrEmpty(Database))
                throw new InvalidDataException("No Database Specified");
            }
            catch (System.Exception e)
            {
            	MessageBox.Show(e.ToString());
            }
        }
        
#endregion

/*
* The connection sub
* This function accepts a label element to allow status messages
* to be relayed to the user.
*  
*/
#region Connect
        public void Connect()
        {
            try
            {
                string ConnString = String.Format("server={0};user id={1}; password={2}; database={3}; pooling=false",
                    this.Server, this.Username, this.Password, this.Database);


                // Initialize connection
                MySqlConnection conn = new MySqlConnection(ConnString);

                //Open connection
                conn.Open();

                MessageBox.Show(String.Format("Connected to {0} as user: {1} at {2}", this.Server, this.Username, DateTime.Now.ToString()));

                conn.Close();
            }
            catch (System.Exception e)
            {
                MessageBox.Show(e.ToString());
            }
        }
#endregion

    }
}
