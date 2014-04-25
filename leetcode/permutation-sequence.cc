class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        if (n <= 0 || k <= 0)
            return ans;

        vector<char> v;
        int factorial = 1;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i + '0');
            factorial *= i;
        }

        factorial /= n;
        --k;
        for (int i = n - 1; i > 0; --i) {
            ans.push_back(v[k / factorial]);
            v.erase(v.begin() + k / factorial);
            k %= factorial;
            factorial /= i;
        }

        ans.push_back(v.back());  //the last one
        return ans;
    }
};
