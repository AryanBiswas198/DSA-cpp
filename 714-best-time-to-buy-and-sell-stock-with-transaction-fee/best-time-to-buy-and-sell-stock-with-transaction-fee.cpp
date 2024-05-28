class Solution {
public:
    int f(int ind, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){
        
        if(ind >= prices.size()){
            return 0;
        }
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        
        if(buy == 0){
            int pick = -prices[ind] + f(ind+1, buy+1, fee, prices, dp);
            int notPick = 0 + f(ind+1, buy, fee, prices, dp);
            
            return dp[ind][buy] = max(pick, notPick);
        }
        else{
            int pick = prices[ind] - fee + f(ind+1, buy-1, fee, prices, dp);
            int notPick = 0 + f(ind+1, buy, fee, prices, dp);
            
            return dp[ind][buy] = max(pick, notPick);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        // Memoization
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return f(0, 0, fee, prices, dp);
    }
};