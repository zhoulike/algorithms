class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
            
        int total_profit = 0, curr = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > curr) {
                total_profit += prices[i] - curr;
                curr = prices[i];
            } else if (prices[i] < curr)
                curr = prices[i];
        }
        
        return total_profit;
    }
};
