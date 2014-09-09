class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> curr;
        sort(S.begin(), S.end());  //guarantee each subset in ascending order
        subsetsBt(ans, curr, S, 0);
        
        return ans;
    }
private:
    void subsetsBt(vector<vector<int> > &ans, vector<int> &curr, vector<int> &s, int start)
    {
        ans.push_back(curr);
        for (int i = start; i < s.size(); ++i) {
            curr.push_back(s[i]);
            subsetsBt(ans, curr, s, i + 1);
            curr.pop_back();
        }
    }
};

class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        sort(S.begin(), S.end());  //guarantee each subset in ascending order
        helper(ans, {}, S, 0);
        
        return ans;
    }
private:
    void helper(vector<vector<int> > &ans, vector<int> curr, vector<int> &s, int start)
    {
        if (start == s.size())
            ans.push_back(curr);
        else {
            helper(ans, curr, s, start + 1);   // do not choose s[start]
            curr.push_back(s[start]);  // choose s[start]
            helper(ans, curr, s, start + 1);
        }
    }
};

class Solution3 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        sort(S.begin(), S.end());  //guarantee each subset in ascending order
        int max = 1 << S.size();  //2^n
        for (int i = 0; i < max; ++i)   //0 ~ (2^n - 1)
            ans.push_back(intToSet(S, i));
        
        return ans;
    }
private:
    vector<int> intToSet(vector<int> &s, int i)
    {
        vector<int> set;
        for (int index = 0; i; i >>= 1, ++index) {
            if (i & 1)
                set.push_back(s[index]);
        }
        return set;
    }
};
