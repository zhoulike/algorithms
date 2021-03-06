class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;

        int lowest = prices[0], max_profit = 0;
        for (decltype(prices.size()) i = 1; i < prices.size(); ++i) {
            if (prices[i] > lowest)
                max_profit += prices[i] - lowest;
            lowest = prices[i];
        }
        return max_profit;
    }
};
