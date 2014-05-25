//turns 4sum to 3sum, then 2sum
//O(n^3)
//runtime: 276ms
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if (num.size() < 4)
            return ans;
            
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1])   //skip duplicates
                continue;
                
            for (int m = i + 1; m < num.size() - 2; ++m) {
                if (m > i + 1 && num[m] == num[m - 1])  //skip duplicates
                    continue;

                int j = m + 1, k = num.size() - 1;
                while (j < k) {  //2sum
                    int sum = num[i] + num[m] + num[j] + num[k];
                    if (sum == target ) {
                        ans.push_back({num[i], num[m], num[j], num[k]});

                        //skip duplicates
                        do {
                            ++j;
                        } while (j < k && num[j] == num[j - 1]);
                        do {
                            --k;
                        } while (k > j && num[k] == num[k + 1]);
                    } else if (sum < target)
                        ++j;
                    else 
                        --k;
                }
            }
        }

        return ans;
    }
};

//turns 4sum to two 2sum
//runtime: 696 ms
class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if (num.size() < 4)
            return ans;

        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int>>> two_sum;
        for (int i = 0; i < num.size() - 1; ++i)
            for (int j = i + 1; j < num.size(); ++j)
                two_sum[num[i] + num[j]].push_back({i, j});

        for (int i = 0; i < num.size() - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1])
                continue;

            for (int j = i + 1; j < num.size() - 2; ++j) {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;

                for (auto p: two_sum[target - num[i] - num[j]])
                    if (p.first > j)
                        ans.push_back({num[i], num[j], num[p.first], num[p.second]});
            }
        }

        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
