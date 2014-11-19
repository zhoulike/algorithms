#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        if (S.empty() || L.empty())
            return ans;

        unordered_map<string, int> patterns;
        for (auto word: L)
            ++patterns[word];

        int len_w = L[0].size(), words = L.size();
        //S.size() >= len_w * words: S = "a", L = ["a", "a"]
        for (int i = 0; S.size() >= len_w * words && i <= S.size() - len_w * words; ++i) {
            unordered_map<string, int> curr;
            int j;
            for (j = 0; j < words; ++j) {
                string word = S.substr(i + j * len_w, len_w);
                if (patterns.find(word) == patterns.end())
                    break;
                ++curr[word];
                if (curr[word] > patterns[word])
                    break;
            }
            if (j == words)
                ans.push_back(i);
        }

        return ans;
    }
};


int main(int argc, char *argv[])
{
    string s = "a";
    vector<string> l = {"a", "a"};
    Solution slt;
    for (auto item: slt.findSubstring(s, l))
        cout << item << endl;
    return 0;
}
