// class Solution {
// public:
//     int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        
//         if(ind >= prices.size()){
//             return 0;
//         }
        
//         if(dp[ind][buy] != -1){
//             return dp[ind][buy];
//         }
        
//         if(buy == 0){
//             int pick = -prices[ind] + f(ind+1, buy+1, prices, dp);
//             int notPick = 0 + f(ind+1, buy, prices, dp);
            
//             return dp[ind][buy] = max(pick, notPick);
//         }
//         else{
//             int pick = prices[ind] + f(ind+2, buy-1, prices, dp);
//             int notPick = 0 + f(ind+1, buy, prices, dp);
            
//             return dp[ind][buy] = max(pick, notPick);
//         }
//     }
    
//     int maxProfit(vector<int>& prices) {
        
//         // Memoization
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
//         return f(0, 0, prices, dp);
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//          // Tabulation
//         int n = prices.size();
//         vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
//         for(int i=n-1; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
                
//                 if(buy == 0){
//                     int pick = -prices[i] + dp[i+1][buy+1];
//                     int notPick = 0 + dp[i+1][buy];
                    
//                     dp[i][buy] = max(pick, notPick);
//                 }
//                 else{
//                     int pick = prices[i] + dp[i+2][buy-1];
//                     int notPick = 0 + dp[i+1][buy];
                    
//                     dp[i][buy] = max(pick, notPick);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
           // Tabulation - space optimisation
        int n = prices.size();
        vector<int> prev1(2, 0); // Tracks 1 index behind
        vector<int> prev2(2, 0); // Tracks 2 indexes behind
        
        for(int i=n-1; i>=0; i--){
            vector<int> curr(2, 0);
            for(int buy=0; buy<=1; buy++){
                
                if(buy == 0){
                    int pick = -prices[i] + prev1[buy+1];
                    int notPick = 0 + prev1[buy];
                    
                    curr[buy] = max(pick, notPick);
                }
                else{
                    int pick = prices[i] + prev2[buy-1];
                    int notPick = 0 + prev1[buy];
                    
                    curr[buy] = max(pick, notPick);
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[0];
    }
};