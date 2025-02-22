class Solution {
public:
    int f(int ind, int amount, vector<vector<int>> &dp, vector<int> &coins) {
        if(ind == 0) {
            if(amount % coins[ind] == 0) {
                return amount / coins[ind];
            }
            return 1e9;
        }

        if(dp[ind][amount] != -1) {
            return dp[ind][amount];
        }
        int pick = 1e9;
        int notPick = f(ind-1, amount, dp, coins);
        if(coins[ind] <= amount) {
            pick = 1 + f(ind, amount-coins[ind], dp, coins);
        }

        return dp[ind][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        // Memoization
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, dp, coins);

        return ans >= 1e9 ? -1 : ans;
    }
};