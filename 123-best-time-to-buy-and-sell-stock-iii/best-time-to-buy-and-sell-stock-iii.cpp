// class Solution {
// public:
//     int f(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        
//         if(ind == prices.size() || k == 0){
//             return 0;
//         }
        
//         if(dp[ind][buy][k] != -1){
//             return dp[ind][buy][k];
//         }
        
//         if(buy == 0){
//             int pick = -prices[ind] + f(ind+1, buy+1, k, prices, dp);
//             int notPick = 0 + f(ind+1, buy, k, prices, dp);
            
//             return dp[ind][buy][k] = max(pick, notPick);
//         }
//         else{
//             int pick = prices[ind] + f(ind+1, buy-1, k-1, prices, dp);
//             int notPick = 0 + f(ind+1, buy, k, prices, dp);
            
//             return dp[ind][buy][k] = max(pick, notPick);
//         }
//     }
    
//     int maxProfit(vector<int>& prices) {
        
//         // Memoization
//         int n = prices.size(), k = 2;
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        
//         return f(0, 0, k, prices, dp);
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//         // Tabulation
//         int n = prices.size(), k = 2;
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
//         for(int i=n-1; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int k=1; k<=2; k++){
//                     if(buy == 0){
//                         int pick = -prices[i] + dp[i+1][buy+1][k];
//                         int notPick = 0 + dp[i+1][buy][k];
                        
//                         dp[i][buy][k] = max(pick, notPick);
//                     }
//                     else{
//                         int pick = prices[i] + dp[i+1][buy-1][k-1];
//                         int notPick = 0 + dp[i+1][buy][k];
                        
//                         dp[i][buy][k] = max(pick, notPick);
//                     }
//                 }
//             }
//         }
//         return dp[0][0][2];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // Tabulation - space optimised
        int n = prices.size(), k = 2;
        vector<vector<int>> dp(2, vector<int>(3, 0));
        
        for(int i=n-1; i>=0; i--){
            vector<vector<int>> temp(2, vector<int>(3, 0));
            for(int buy=0; buy<=1; buy++){
                for(int k=1; k<=2; k++){
                    
                    if(buy == 0){
                        int pick = -prices[i] + dp[buy+1][k];
                        int notPick = 0 + dp[buy][k];
                        
                        temp[buy][k] = max(pick, notPick);
                    }
                    else{
                       int pick = prices[i] + dp[buy-1][k-1];
                       int notPick = 0 + dp[buy][k];
                        
                       temp[buy][k] = max(pick, notPick); 
                    }
                }
            }
            dp = temp;
        }
        
        return dp[0][2];
    }
};