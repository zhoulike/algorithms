#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) {
        string lineBuffer;
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
           continue; 
        else {
            for (char &ch: lineBuffer) {
                if (isupper(ch))
                    ch = tolower(ch);
                else if (islower(ch))
                    ch = toupper(ch);
            }
        }
        cout << lineBuffer << endl;
    }
    return 0;
}
