class Solution {
public:
    int f(int ind, int buy, vector<vector<int>> &dp, vector<int> &prices, int fee) {
        if(ind >= prices.size()) {
            return 0;
        }

        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        if(buy == 0) {
            int notPick = f(ind+1, buy, dp, prices, fee);
            int pick = -prices[ind] + f(ind+1, buy+1, dp, prices, fee);

            return dp[ind][buy] = max(pick, notPick);
        }
        else{
            int notPick = f(ind+1, buy, dp, prices, fee);
            int pick = prices[ind] - fee + f(ind+1, buy-1, dp, prices, fee);

            return dp[ind][buy] = max(pick, notPick);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        // Memoization
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 0, dp, prices, fee);
    }
};