#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    string s1s1 = s1 + s1;
    if (s1s1.find(s2) == string::npos)
        return false;
    return true;
}

int main(int argc, char *argv[])
{
    cout << isRotation("waterbottle", "erbottlewat") << endl;
    cout << isRotation("waterbottle", "eebottlewat") << endl;
    return 0;
}
