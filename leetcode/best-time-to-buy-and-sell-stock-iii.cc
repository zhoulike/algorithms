#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//O(n^2)
class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int left = single(prices, 0, i),
                right = single(prices, i, prices.size());
            profit = max(profit, left + right);
        }

        return profit;
    }
private:
    int single(vector<int> &prices, int begin, int end)
    {
        if (end - begin <= 1)
            return 0;

        int smallest = prices[begin++], profit = 0;
        while (begin < end) {
            if (prices[begin] < smallest)
                smallest = prices[begin];
            else if (prices[begin] - smallest > profit)
                profit = prices[begin] - smallest;
            ++begin;
        }

        return profit;
    }
};

//O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        vector<int> forward(prices.size(), 0), backward(prices.size(), 0);

        int smallest = prices.front();
        for (int i = 1; i < prices.size(); ++i) {
            smallest = min(smallest, prices[i]);
            forward[i] = max(prices[i] - smallest, forward[i - 1]);
        }

        int largest = prices.back();
        for (int i = prices.size() - 2; i >= 0; --i) {
            largest = max(largest, prices[i]);
            backward[i] = max(largest - prices[i], backward[i + 1]);
        }

        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) 
            profit = max(profit, forward[i] + backward[i]);

        return profit;
    }
};

int main(int argc, char *argv[])
{
    vector<int> p{6, 1, 3, 2, 4, 7};
    Solution s;
    cout << s.maxProfit(p) << endl;
    return 0;
}
