#include <fstream>

using namespace std;

int main()
{
    ofstream SaveFile("cpp-home.txt");
    SaveFile << "Hello, Hi!";
    SaveFile.close();
    return 0;
}
