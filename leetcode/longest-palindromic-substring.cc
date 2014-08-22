#include <iostream>
#include <string>
#include <vector>

using namespace std;

//DP solution: O(n^2) time, O(n^2) space
class Solution1 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1)
            return s;

        vector<vector<bool>> vec(len, vector<bool>(len, false));
        int start = 0, max_len = 1;
        for (int i = 0; i < len; ++i)
            vec[i][i] = true;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                vec[i][i + 1] = true;
                if (max_len < 2) {
                    max_len = 2;
                    start = i;
                }
            }
        }

        for (int chars = 3; chars <= len; ++chars) { //length of substr
            for (int i = 0; i <= len - chars; ++i) {
                int j = i + chars - 1;  //substr = s[i...j], including s[j]

                if (s[i] == s[j] && vec[i + 1][j - 1]) {
                    vec[i][j] = true;
                    if (chars > max_len) {
                        max_len = chars;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, max_len);
    }
};

class Solution2 {  
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        string longest;
        for (int i = 0; i < s.size() - 1; ++i) {
            string tmp = expand(s, i, i); //odd characters, e.g. "aca"
            if (tmp.size() > longest.size())
                longest = tmp;
            
            tmp = expand(s, i, i + 1); //even characters, e.g. "bb"
            if (tmp.size() > longest.size())
                longest = tmp;
        }
        return longest;
    }
private:
    string expand(string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};

//O(n) time, O(n) space
//Manacher's algorithm
class Solution3 {  
public:
    string longestPalindrome(string s) {
        string new_str = preProcess(s);
        vector<int> radius(new_str.size(), 0);
        int center = 0, right = 0;
        int max_len = 0, max_center = 0;
        for (int i = 1; i < new_str.size() - 1; ++i) {
            int i_mirror = 2 * center - i; //i - (center - i)
            radius[i] = (right > i)? min(right - i, radius[i_mirror]): 0;

            //attempt to expand palindrome centered at i
            //i.e. expands RIGHT, at most expand N times
            while (new_str[i - radius[i] - 1] == new_str[i + radius[i] + 1])
                ++radius[i];

            if (i + radius[i] > right) {
                center = i;
                right = i + radius[i];
            }

            //find max
            if (radius[i] > max_len) {
                max_len = radius[i];
                max_center = i;
            }
        }
        //substract one sentinel and radius
        return s.substr((max_center - 1 - max_len) / 2, max_len);
    }
private:
    string preProcess(string& orig)
    {
        if (orig.empty())
            return "^&";  //^ and & are sentinels to avoid bounds checking
        string new_str = "^#";
        for (auto ch: orig) {
            new_str.push_back(ch);
            new_str.push_back('#');
        }
        new_str += "&";
        return new_str;
    }
};


int main(int argc, char *argv[])
{
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    cout << s1.longestPalindrome(argv[1]) << endl;
    cout << s2.longestPalindrome(argv[1]) << endl;
    cout << s3.longestPalindrome(argv[1]) << endl;
    return 0;
}
