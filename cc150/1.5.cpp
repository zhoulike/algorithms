#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

string itoa(int num)
{
    stack<char> s;
    while (num) {
        s.push(num % 10 + '0');
        num /= 10;
    }

    string ret;
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }

    return ret;
}

string itoa2(int num)
{
    stringstream sstrm;
    sstrm << num;
    return sstrm.str();
}

//O(n) time, O(n) space
string compression(string s)
{
    string ret;
    char curr;
    int count = 0;
    for (string::size_type i = 0; i < s.size(); ++i) {
        if (count == 0)
            curr = s[i];
        ++count;

        if (i + 1 == s.size() || s[i + 1] != curr) {
            ret.push_back(curr);
            ret += itoa2(count);
            count = 0;
        }
    }

    return ret.size() < s.size()? ret: s;
}


int main(int argc, char *argv[])
{
    cout << compression("aabcccccaaa") << endl;
    cout << compression("abcad") << endl;
    cout << compression("abcadd") << endl;
    cout << compression("aaaaaaaaaaa") << endl;
    return 0;
}
