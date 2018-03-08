#include <iostream>
#include <fstream>

using namespace std;

int main()
{
     ifstream file("book.txt");
     
     char ch;
     while(!file.eof())
     {
         file.get(ch);
         cout << ch;
         
         for(int i=0; i<100000000; i++);
     }
     
     file.close();
     
     return 0;
}

