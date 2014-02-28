class Solution {
public:
    int numTrees(int n) {
    	if(n <= 0)
    		return 0;

        vector<int> v(n + 1, 0);
        v[0] = 1;  //v[0] = 1 is better than v[0] = 0
        for (int i = 1; i <= n; ++i)
        	for (int j = 1; j <= i; ++j)
                v[i] += v[i - j] * v[j - 1];

        return v[n];
    }
};s