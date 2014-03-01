class Solution {
public:
    int numDecodings(string s) {
    	if (s.size() == 0)
    		return 0;

        vector<int> v(s.size(), 0);
        if (s[0] != '0')
        	v[0] = 1;

        for (int i = 1; i < s.size(); ++i) {
        	if (s[i] != '0')
        		v[i] += v[i - 1];

        	int val = (s[i - 1] - '0') * 10 + s[i] - '0';
        	if (val >= 10 && val <= 26) {
        		if (i >= 2)
        			v[i] += v[i - 2];
        		else
        			++v[i];
        	}
        }

        return v[s.size() - 1];
    }
};