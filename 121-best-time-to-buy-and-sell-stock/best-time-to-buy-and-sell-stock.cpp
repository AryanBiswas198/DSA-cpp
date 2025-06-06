class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), maxProfit = 0, minCost = prices[0];
        for(int i=0; i<n; i++) {
            minCost = min(minCost, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minCost);
        }
        return maxProfit;
    }
};