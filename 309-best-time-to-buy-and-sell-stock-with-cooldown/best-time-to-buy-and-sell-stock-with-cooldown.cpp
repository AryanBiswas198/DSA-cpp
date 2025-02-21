class Solution {
public:
    int f(int ind, int buy, vector<vector<int>> &dp, vector<int> &prices) {
        if(ind >= prices.size()) {
            return 0;
        }

        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        if(buy == 0) {
            int notPick = 0 + f(ind+1, buy, dp, prices);
            int pick = -prices[ind] + f(ind+1, buy+1, dp, prices);

            return dp[ind][buy] = max(pick, notPick);
        }
        else{
            int notPick = 0 + f(ind+1, buy, dp, prices);
            int pick = prices[ind] + f(ind+2, buy-1, dp, prices);

            return dp[ind][buy] = max(pick, notPick);
        }
    }

    int maxProfit(vector<int>& prices) {
        // Memoization
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 0, dp, prices);
    }
};