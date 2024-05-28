class Solution {
public:
    int f(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        
        if(ind == prices.size() || k == 0){
            return 0;
        }
        
        if(dp[ind][buy][k] != -1){
            return dp[ind][buy][k];
        }
        
        if(buy == 0){
            int pick = -prices[ind] + f(ind+1, buy+1, k, prices, dp);
            int notPick = 0 + f(ind+1, buy, k, prices, dp);
            
            return dp[ind][buy][k] = max(pick, notPick);
        }
        else{
            int pick = prices[ind] + f(ind+1, buy-1, k-1, prices, dp);
            int notPick = 0 + f(ind+1, buy, k, prices, dp);
            
            return dp[ind][buy][k] = max(pick, notPick);
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        // Memoization
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return f(0, 0, k, prices, dp);
    }
};