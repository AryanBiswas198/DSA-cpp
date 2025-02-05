class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), minPrice = INT_MAX, profit = INT_MIN;
        for(auto it: prices) {
            minPrice = min(minPrice, it);
            profit = max(profit, abs(minPrice - it));
        }
        return profit;
    }
};