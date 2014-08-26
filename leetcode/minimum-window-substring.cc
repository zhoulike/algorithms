#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> orig, curr;
        for (auto ch: T) {
            ++orig[ch];
            curr[ch] = 0;
        }

        int start = -1, min_len = INT_MAX;
        int begin = 0, end = 0;

        while (1) {
            if (!containsAll(orig, curr)) {
                if (end >= S.size())
                    break;
                if (orig.find(S[end]) != orig.end())
                    ++curr[S[end]];
                ++end;
            } else {
                if (end - begin < min_len) {
                    start = begin;
                    min_len = end - begin;
                }
                if (curr.find(S[begin]) != curr.end())
                    --curr[S[begin]];
                ++begin;
            }
        }

        return start == -1? "": S.substr(start, min_len);
    }
private:
    bool containsAll(unordered_map<char, int>& orig, unordered_map<char, int>& curr)
    {
        for (auto p: orig)
            if (curr[p.first] < p.second)
                return false;
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.minWindow(argv[1], argv[2]) << endl;
    return 0;
}
