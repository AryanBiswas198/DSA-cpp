class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Tabulation
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        for(int amt=0; amt<=amount; amt++) {
            if(amt % coins[0] == 0) {
                dp[0][amt] = amt / coins[0];
            }
        }

        for(int i=1; i<n; i++) {
            for(int amt=0; amt<=amount; amt++) {
                int notPick = dp[i-1][amt];
                int pick = 1e9;
                if(coins[i] <= amt) {
                    pick = 1 + dp[i][amt-coins[i]];
                }

                dp[i][amt] = min(pick, notPick);
            }
        }

        return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    }
};