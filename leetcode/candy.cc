//O(n): 180ms
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 0);
        stack<int> stk;
        ratings.push_back(INT_MAX);  //dummy

        for (int i = 0; i < ratings.size(); ) {
            if (stk.empty() || ratings[stk.top()] > ratings[i])  //push descendant elements
                stk.push(i++);
            else {
                while (!stk.empty()) {
                    int j = stk.top();
                    stk.pop();
                    int neighbor = 0;
                    if (j - 1 >= 0 && ratings[j - 1] < ratings[j])
                        neighbor = max(neighbor, candy[j - 1]);
                    if (j + 1 < ratings.size() && ratings[j] > ratings[j + 1])
                        neighbor = max(neighbor, candy[j + 1]);
                    candy[j] = neighbor + 1;
                }
            }
        }  //after the loop, stk still has one element: dummy
        ratings.pop_back();
        return accumulate(candy.begin(), candy.end(), 0);
    }
};

//O(n): 116ms
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)  //forward
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        for (int i = ratings.size() - 2; i >= 0; --i)  //backward
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) //need compare candy
                candy[i] = candy[i + 1] + 1;
        return accumulate(candy.begin(), candy.end(), 0);
    }
};
