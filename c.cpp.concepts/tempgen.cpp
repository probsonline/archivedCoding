#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream extrFile("extr.h");
    ofstream srcFile("src.c");
    char ch;
    char line[100];
    
    while(!extrFile.eof())
    {
        extrFile.get(ch);                          
//        srcFile.open("src.c", ios::ate);
        srcFile << ch;
//        srcFile.close();
        cout << ch;
        for(int i=0; i<10000000; i++);
         /*      
        extrFile.getline(line, 100);
        srcFile.open("src2.c", ios::ate);
        srcFile << line;
        cout << line << endl;
        srcFile.close();
        */
    }
    
    srcFile.close();
    extrFile.close();
    return 0;
}
