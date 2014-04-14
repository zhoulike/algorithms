//KMP solution
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = strlen(haystack), n = strlen(needle);
        if (n == 0)  //remember: "" is the subset of any strings
            return haystack;

        int curr = 0;
        vector<int> prefix = compute_prefix(needle);

        for (int i = 0; i < m; ++i) {
            while (curr > 0 && needle[curr] != haystack[i])
                curr = prefix[curr - 1];
            if (needle[curr] == haystack[i])
                ++curr;
            if (curr == n)
                return haystack + i - n + 1;
        }

        return NULL;
    }
private:
    vector<int> compute_prefix(char *pattern)
    {
        int len = strlen(pattern);
        
        int curr = 0;
        vector<int> prefix(len);
        prefix[0] = 0;

        for (int i = 1; i < len; ++i) {
            while (curr > 0 && pattern[curr] != pattern[i])
                curr = prefix[curr - 1];

            if (pattern[curr] == pattern[i]) 
                ++curr;
            prefix[i] = curr;
        }

        return prefix;
    }
};