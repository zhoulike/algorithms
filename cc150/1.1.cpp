#include <iostream>
#include <string>
#include <map>

using namespace std;

/*All: O(n) time, O(1) space*/
bool unique(string s)
{
    map<char, int> m;

    for (string::size_type i = 0; i < s.size(); ++i) {
        if (m.find(s[i]) == m.end())
            m[s[i]] = 1;
        else
            return false;
    }
    return true;
}

bool unique2(string s)
{
    if (s.size() > 256)
        return false;

    bool dict[256] = {false};
    
    for (string::size_type i = 0; i < s.size(); ++i) {
        if (dict[s[i] - 0] == false) {
            dict[s[i] - 0] = true;
        } else
            return false;
    }
    return true;
}

bool unique3(string s)
{
    if (s.size() > 256)
        return false;

    char dict[256/8] = {0};
    
    for (string::size_type i = 0; i < s.size(); ++i) {
        int pos = s[i] / 8,
            shift = 1 << (s[i] % 8);
        if ((dict[pos] & shift) == 0) {
            dict[pos] |= shift;
        } else
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    cout << "abcd is " << (unique("abcd")? " ":"not ") << "unique" << endl;
    cout << "abcb is " << (unique("abcb")? " ":"not ") << "unique" << endl;
    cout << " is " << (unique(" ")? " ":"not ") << "unique" << endl;
    cout << "a is " << (unique("a")? " ":"not ") << "unique" << endl;

    cout << "abcd is " << (unique2("abcd")? " ":"not ") << "unique" << endl;
    cout << "abcb is " << (unique2("abcb")? " ":"not ") << "unique" << endl;
    cout << " is " << (unique2(" ")? " ":"not ") << "unique" << endl;
    cout << "a is " << (unique2("a")? " ":"not ") << "unique" << endl;

    cout << "abcd is " << (unique3("abcd")? " ":"not ") << "unique" << endl;
    cout << "abcb is " << (unique3("abcb")? " ":"not ") << "unique" << endl;
    cout << " is " << (unique3(" ")? " ":"not ") << "unique" << endl;
    cout << "a is " << (unique3("a")? " ":"not ") << "unique" << endl;
    return 0;
}
