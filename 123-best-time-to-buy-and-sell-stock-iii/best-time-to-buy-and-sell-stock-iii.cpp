class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Tabulation - space optimised
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));

        for(int i=n-1; i>=0; i--) {
            vector<vector<int>> curr(2, vector<int>(3, 0));
            for(int buy=0; buy<=1; buy++) {
                for(int transactions=1; transactions<=2; transactions++) {
                    if(buy == 0) {
                        int notPick = dp[buy][transactions];
                        int pick = -prices[i] + dp[buy+1][transactions];

                        curr[buy][transactions] = max(pick, notPick);
                    }
                    else{
                        int notPick = dp[buy][transactions];
                        int pick = prices[i] + dp[buy-1][transactions-1];

                        curr[buy][transactions] = max(pick, notPick);
                    }
                }
            }
            dp = curr;
        }
        return dp[0][2];
    }
};