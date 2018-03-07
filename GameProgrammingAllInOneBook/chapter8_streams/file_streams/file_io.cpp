#include <iostream>
#include <fstream.h>

void PracticeStreams(void);
void StreamIO(void);
void LineCountMarker(void);

int main(int argc, char *argv)
{

//	PracticeStreams();
	std::cout <<" ----------  First Program Ended ----------  \n\n";

//	StreamIO();
	std::cout << " ---------- Second Program Ended ---------- \n\n";

	LineCountMarker();
	std::cout << " ---------- Third Program Ended ---------- \n\n";

	return 0;

}

void PracticeStreams(void)
{	
    fstream file1, file2, file3;

    /* Open file1 for output in text mode. */
    file1.open("file1.txt", ios::out);

    /* Open file2 for output in binary mode. */
    file2.open("file2.bin", ios::out | ios::binary);

    /* Open file3 for appending in text mode. */
    file3.open("file3.txt", ios::out | ios::app);

    /* Close all files. */
    file1.close();
    file2.close();
    file3.close();

    /* Open file1.txt without recreating/replacing it to append to it. */
    file1.open("file1.txt", (ios::out | ios::nocreate | ios::app));

    if(file1.is_open())
    {
        std::cout << "file1.txt is open to editing" << std::endl;
    }
    else
    {
        std::cout << "file1.txt couldn't be opened" << std::endl;
    }

    file1.close();

}

void StreamIO(void)
{
	fstream file;

	char firstName[50];
	char lastName[50];
	char marital_status[8];
	int age;
	char married;

	/* Open a file to contain the data. */
	file.open("Data.txt", ios::out);

	if(file.is_open())
	{
		std::cout << "What is your first Name" << std::endl;
		std::cin >> firstName;

		std::cout << "What is your last Name" << std::endl;
		std::cin >> lastName;

		std::cout << "What is your age" << std::endl;
		std::cin >> age;

		std::cout << "Are you married (y/n)" << std::endl;
		std::cin >> married;

		/* Write all the data in the file. */
		file << firstName << " " << lastName << " " << age << ((married == 'y' || married == 'Y')? " married\n" : " single\n") ;

		file.close();

		/* Reset the variables. */
		age=0;
		married=-1;

		/* Open the file for reading. */
		file.open("Data.txt", ios::in);

		file >> firstName >> lastName >> age >> marital_status;

		/* Show all the data to the user. */
		std::cout << firstName << " " << lastName << " " << age << " years " << marital_status << std::endl;

		file.close();
	}
	else
	{
		std::cout << "Error in opening the file" << std::endl;
	}
}

void LineCountMarker(void)
{
	fstream inputFile, outputFile;
	int lineCount=0;
	char inLine[256];
	char outLine[256];

	inputFile.open("file_io.cpp", ios::in);

	if(inputFile.is_open())
	{
		/* Open file for writing the formatted output. */
		outputFile.open("f_file_io.cpp", ios::out);

		while(inputFile.peek() != EOF)
		{
			lineCount++;

			/* Get 256 character line from the file. */
			inputFile.getline(inLine, 256);

			/* Format the line with line number. */
			sprintf(outLine, "%ld: %s\n", lineCount, inLine);

			/* Output the line to the output file. */
			outputFile << outLine;
		}

		outputFile.close();
		inputFile.close();
	}
	else
	{
		std::cout << "Failed in opening the file" <<std::endl;
	}
}
