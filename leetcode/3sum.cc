class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ans;
        if (num.size() < 3)
            return ans;
            
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            if (i > 0 && num[i] == num[i - 1]) //skip duplicates
                continue;

            int j = i + 1, k = num.size() - 1;
            while (j < k) {  //turns 3sum to 2sum
                if (num[j] + num[k] == -num[i]) {
                    ans.push_back({num[i], num[j], num[k]});

                    //skip duplicates
                    do {
                        ++j;
                    } while (j < k && num[j] == num[j - 1]);
                    do {
                        --k;
                    } while (k > j && num[k] == num[k + 1]);
                } else if (num[j] + num[k] < -num[i])
                    ++j;
                else 
                    --k;
            }
        }

        return ans;
    }
};
