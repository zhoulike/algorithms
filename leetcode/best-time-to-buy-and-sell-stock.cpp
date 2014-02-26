class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 0)
            return 0;
            
        vector<int> profit(prices.size());
        int min = prices[0], max = profit[0] = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] < min)
                min = prices[i];
            profit[i] = prices[i] - min;
            if(profit[i] > max)
                max = profit[i];
        }
        
        return max;
    }
};