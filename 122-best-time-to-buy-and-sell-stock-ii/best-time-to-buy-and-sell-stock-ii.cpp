class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Tabulation - space optimised
        int n = prices.size();
        vector<int> dp(2, 0);

        for(int i=n-1; i>=0; i--) {
            vector<int> curr(2, 0);
            for(int buy=0; buy<=1; buy++) {
                if(buy == 0) {
                    int notPick = dp[buy];
                    int pick = -prices[i] + dp[buy+1];

                    curr[buy] = max(pick, notPick);
                }
                else{
                    int notPick = dp[buy];
                    int pick = prices[i] + dp[buy-1];

                    curr[buy] = max(pick, notPick);
                }
            }
            dp = curr;
        }
        return dp[0];
    }
};