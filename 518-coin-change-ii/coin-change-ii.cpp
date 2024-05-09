class Solution {
public:
    int f(int ind, int amount, vector<vector<int>> &dp, vector<int> &coins){
        
        if(ind == 0){
            if(amount % coins[ind] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        
        int notPick = f(ind-1, amount, dp, coins);
        int pick = 0;
        
        if(coins[ind] <= amount){
            pick = f(ind, amount-coins[ind], dp, coins);
        }
        
        return dp[ind][amount] = pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        
        // Memoization
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        int ans = f(n-1, amount, dp, coins);
        
        return ans == -1 ? 0 : ans;
    }
};