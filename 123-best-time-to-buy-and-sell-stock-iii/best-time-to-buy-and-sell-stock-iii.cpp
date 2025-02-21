class Solution {
public:
    int f(int ind, int buy, int transactions, vector<vector<vector<int>>> &dp, vector<int> &prices) {
        if(ind == prices.size() || transactions >= 2) {
            return 0;
        }

        if(dp[ind][buy][transactions] != -1) {
            return dp[ind][buy][transactions];
        }

        if(buy == 0) {
            int notPick = f(ind+1, buy, transactions, dp, prices);
            int pick = -prices[ind] + f(ind+1, buy+1, transactions, dp, prices);

            return dp[ind][buy][transactions] = max(pick, notPick);
        }
        else{
            int notPick = f(ind+1, buy, transactions, dp, prices);
            int pick = prices[ind] + f(ind+1, buy-1, transactions+1, dp, prices);

            return dp[ind][buy][transactions] = max(pick, notPick);
        }
    }

    int maxProfit(vector<int>& prices) {
        // Memoization
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(0, 0, 0, dp, prices);
    }
};