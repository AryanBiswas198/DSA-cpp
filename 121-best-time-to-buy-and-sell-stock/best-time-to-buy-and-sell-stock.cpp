class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), maxProfit = 0, minVal = INT_MAX;
        for(int i=0; i<n; i++) {
            minVal = min(prices[i], minVal);
            maxProfit = max(maxProfit, prices[i] - minVal);
        }
        return maxProfit;
    }
};