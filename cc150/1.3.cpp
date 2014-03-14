#include <iostream>
#include <string>

using namespace std;

inline void count(string &s, int a[], int n)
{
    for (string::size_type i = 0; i < s.size(); ++i)
        ++a[s[i] - 0];
}

//O(n) time, O(1) space
bool isPermutation(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    int a1[256] = {0},
        a2[256] = {0};

    count(s1, a1, 256);
    count(s2, a2, 256);

    for (int i = 0; i < 256; ++i) {
        if (a1[i] != a2[i])
            return false;
    }

    return true;
}

bool isPermutation2(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    int a[256] = {0};
    count(s1, a, 256);

    for (string::size_type i = 0; i < s2.size(); ++i) {
        if (--a[s2[i] - 0] < 0)
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    cout << "abcd -> cdba?" << (isPermutation("abcd", "cbda")? "true":"false") << endl;
    cout << "abcd -> cda?" << (isPermutation("abcd", "cda")? "true":"false") << endl;
    cout << "abcd -> cdda?" << (isPermutation("abcd", "cdda")? "true":"false") << endl;
    cout << " -> ?" << (isPermutation(" ", " ")? "true":"false") << endl;

    cout << "abcd -> cdba?" << (isPermutation2("abcd", "cbda")? "true":"false") << endl;
    cout << "abcd -> cda?" << (isPermutation2("abcd", "cda")? "true":"false") << endl;
    cout << "abcd -> cdda?" << (isPermutation2("abcd", "cdda")? "true":"false") << endl;
    cout << " -> ?" << (isPermutation2(" ", " ")? "true":"false") << endl;
    return 0;
}
