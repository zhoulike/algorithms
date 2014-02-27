class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.size() == 0)
    		return 0;

        vector<int> v(s.size(), 0);
        v[0] = 1;
        int max_length = 1;
        
        for (int i = 1; i < s.size(); ++i)
        {
        	int j = i - 1;
        	while(j >= 0 && s[i] != s[j] && s[j] != 1)
        		--j;
        	v[i] = min(i - j, v[i - 1] + 1); //mention: v[i] = i - j is wrong.
        	max_length = max(max_length, v[i]);
        }

        return max_length;
    }
};