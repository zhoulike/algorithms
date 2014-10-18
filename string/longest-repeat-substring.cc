//find the longest repeat substring in a string
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int common(const string& s1, const string& s2)
{
    int i = 0;
    while (i < s1.size() && i < s2.size() && s1[i] == s2[i])
        ++i;
    return i;
}

//straight-forward solution
string repeat1(string s)
{
    int max_len = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
        string s1 = s.substr(i);
        for (int j = i + 1; j < s.size(); ++j) {
            string s2 = s.substr(j);
            int len = common(s1, s2);
            if (len > max_len) {
                max_len = len;
                start = i;
            }
        }
    }
    return s.substr(start, max_len);
}

//solution using suffix array
string repeat2(string s)
{
    vector<string> suffix;
    for (int i = 0; i < s.size(); ++i)
        suffix.push_back(s.substr(i));
    sort(suffix.begin(), suffix.end());
    
    int max_len = 0;
    string ans;
    for (int i = 0; i < suffix.size() - 1; ++i) {
        int len = common(suffix[i], suffix[i + 1]);
        if (len > max_len) {
            max_len = len;
            ans = suffix[i].substr(0, max_len);
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    vector<string> vs = {"abcdeabef", "aaaaa", "aabbb", "abcdabcd"};
    for (auto s: vs) {
        cout << repeat1(s) << " " << repeat2(s) << endl;
    }
    return 0;
}
