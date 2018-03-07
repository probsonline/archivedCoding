1: #include <iostream>
2: #include <fstream.h>
3: 
4: void PracticeStreams(void);
5: void StreamIO(void);
6: void LineCountMarker(void);
7: 
8: int main(int argc, char *argv)
9: {
10: 
11: //	PracticeStreams();
12: 	std::cout <<" ----------  First Program Ended ----------  \n\n";
13: 
14: //	StreamIO();
15: 	std::cout << " ---------- Second Program Ended ---------- \n\n";
16: 
17: 	LineCountMarker();
18: 	std::cout << " ---------- Third Program Ended ---------- \n\n";
19: 
20: 	return 0;
21: 
22: }
23: 
24: void PracticeStreams(void)
25: {	
26:     fstream file1, file2, file3;
27: 
28:     /* Open file1 for output in text mode. */
29:     file1.open("file1.txt", ios::out);
30: 
31:     /* Open file2 for output in binary mode. */
32:     file2.open("file2.bin", ios::out | ios::binary);
33: 
34:     /* Open file3 for appending in text mode. */
35:     file3.open("file3.txt", ios::out | ios::app);
36: 
37:     /* Close all files. */
38:     file1.close();
39:     file2.close();
40:     file3.close();
41: 
42:     /* Open file1.txt without recreating/replacing it to append to it. */
43:     file1.open("file1.txt", (ios::out | ios::nocreate | ios::app));
44: 
45:     if(file1.is_open())
46:     {
47:         std::cout << "file1.txt is open to editing" << std::endl;
48:     }
49:     else
50:     {
51:         std::cout << "file1.txt couldn't be opened" << std::endl;
52:     }
53: 
54:     file1.close();
55: 
56: }
57: 
58: void StreamIO(void)
59: {
60: 	fstream file;
61: 
62: 	char firstName[50];
63: 	char lastName[50];
64: 	char marital_status[8];
65: 	int age;
66: 	char married;
67: 
68: 	/* Open a file to contain the data. */
69: 	file.open("Data.txt", ios::out);
70: 
71: 	if(file.is_open())
72: 	{
73: 		std::cout << "What is your first Name" << std::endl;
74: 		std::cin >> firstName;
75: 
76: 		std::cout << "What is your last Name" << std::endl;
77: 		std::cin >> lastName;
78: 
79: 		std::cout << "What is your age" << std::endl;
80: 		std::cin >> age;
81: 
82: 		std::cout << "Are you married (y/n)" << std::endl;
83: 		std::cin >> married;
84: 
85: 		/* Write all the data in the file. */
86: 		file << firstName << " " << lastName << " " << age << ((married == 'y' || married == 'Y')? " married\n" : " single\n") ;
87: 
88: 		file.close();
89: 
90: 		/* Reset the variables. */
91: 		age=0;
92: 		married=-1;
93: 
94: 		/* Open the file for reading. */
95: 		file.open("Data.txt", ios::in);
96: 
97: 		file >> firstName >> lastName >> age >> marital_status;
98: 
99: 		/* Show all the data to the user. */
100: 		std::cout << firstName << " " << lastName << " " << age << " years " << marital_status << std::endl;
101: 
102: 		file.close();
103: 	}
104: 	else
105: 	{
106: 		std::cout << "Error in opening the file" << std::endl;
107: 	}
108: }
109: 
110: void LineCountMarker(void)
111: {
112: 	fstream inputFile, outputFile;
113: 	int lineCount=0;
114: 	char inLine[256];
115: 	char outLine[256];
116: 
117: 	inputFile.open("file_io.cpp", ios::in);
118: 
119: 	if(inputFile.is_open())
120: 	{
121: 		/* Open file for writing the formatted output. */
122: 		outputFile.open("f_file_io.cpp", ios::out);
123: 
124: 		while(inputFile.peek() != EOF)
125: 		{
126: 			lineCount++;
127: 
128: 			/* Get 256 character line from the file. */
129: 			inputFile.getline(inLine, 256);
130: 
131: 			/* Format the line with line number. */
132: 			sprintf(outLine, "%ld: %s\n", lineCount, inLine);
133: 
134: 			/* Output the line to the output file. */
135: 			outputFile << outLine;
136: 		}
137: 
138: 		outputFile.close();
139: 		inputFile.close();
140: 	}
141: 	else
142: 	{
143: 		std::cout << "Failed in opening the file" <<std::endl;
144: 	}
145: }
