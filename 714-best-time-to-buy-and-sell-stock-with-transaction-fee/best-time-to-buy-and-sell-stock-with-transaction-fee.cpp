class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Tabulation
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy == 0) {
                    int notPick = dp[i+1][buy];
                    int pick = -prices[i] + dp[i+1][buy+1];

                    dp[i][buy] = max(pick, notPick);
                }
                else{
                    int notPick = dp[i+1][buy];
                    int pick = prices[i] - fee + dp[i+1][buy-1];

                    dp[i][buy] = max(pick, notPick);
                }
            }
        }
        return dp[0][0];
    }
};