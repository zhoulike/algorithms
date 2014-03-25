class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        permute_iter(ret, num, 0, num.size());
        return ret;
    }
private:
    void permute_iter(vector<vector<int> > &ret, vector<int> &num, int start, int end) {
        if (start == end)
            ret.push_back(vector<int>(num));
        
        for (int i = start; i < end; ++i) {
            swap(num[start], num[i]);
            permute_iter(ret, num, start + 1, end);
            swap(num[start], num[i]);
        }
    }
};