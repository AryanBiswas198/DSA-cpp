// class Solution {
// public:
//     int f(int ind, int amount, vector<vector<int>> &dp, vector<int> &coins){
        
//         if(ind == 0){
//             if(amount % coins[ind] == 0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
        
//         if(dp[ind][amount] != -1){
//             return dp[ind][amount];
//         }
        
//         int notPick = f(ind-1, amount, dp, coins);
//         int pick = 0;
        
//         if(coins[ind] <= amount){
//             pick = f(ind, amount-coins[ind], dp, coins);
//         }
        
//         return dp[ind][amount] = pick + notPick;
//     }
    
//     int change(int amount, vector<int>& coins) {
        
//         // Memoization
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
//         int ans = f(n-1, amount, dp, coins);
        
//         return ans == -1 ? 0 : ans;
//     }
// };

    
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         // Tabulation
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
//         for(int i=0; i<=amount; i++){
//             if(i % coins[0] == 0){
//                 dp[0][i] = 1;
//             }
//         }
        
//         for(int i=1; i<n; i++){
//             for(int amt=0; amt<=amount; amt++){
//                 int notPick = dp[i-1][amt];
//                 int pick = 0;
//                 if(coins[i] <= amt){
//                     pick = dp[i][amt-coins[i]];
//                 }
                
//                 dp[i][amt] = pick + notPick;
//             }
//         }
        
//         int ans = dp[n-1][amount];
        
//         return ans == 0 ? 0 : ans;
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        // Tabulation Space optimised
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[i] = 1;
            }
        }
        
        for(int i=1; i<n; i++){
            vector<int> temp(amount+1, 0);
            for(int amt=0; amt<=amount; amt++){
                int notPick = dp[amt];
                int pick = 0;
                if(coins[i] <= amt){
                    pick = temp[amt-coins[i]];
                }
                
                temp[amt] = pick + notPick;
            }
            dp = temp;
        }
        
        int ans = dp[amount];
        
        return ans == 0 ? 0 : ans;
    }
};
