//http://en.wikipedia.org/wiki/Gray_code

//basic solution
Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);  //if n == 0, answer is {0};
        
        int len = 1 << n;
        for (int i = 1; i < len; i += 2) {
            ans.push_back(ans.back() ^ 1);  //change LSB
            int j = 0;
            while ((ans.back() & (1 << j)) == 0)  //find first 1 from LSB to MSB
                ++j;
            ++j; //left of the first 1
            if (j == n) //end
                break;
            ans.push_back(ans.back() ^ (1 << j));
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1 << n; //the number of gray code: 2^n
        vector<int> ans;
        for (int i = 0; i < len; ++i)
            ans.push_back((i >> 1) ^ i);
        return ans;
    }
};
