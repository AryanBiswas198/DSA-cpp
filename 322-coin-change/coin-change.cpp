// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
        
//         // Tabulation
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        
//         for(int t=0; t<=amount; t++){
//             if(t%coins[0] == 0){
//                 dp[0][t] = t / coins[0];
//             }
//         }
        
//         for(int i=1; i<n; i++){
//             for(int val=0; val<=amount; val++){
                
//                 int notPick = dp[i-1][val];
//                 int pick = 1e9;
//                 if(coins[i] <= val){
//                     pick = 1 + dp[i][val-coins[i]];
//                 }
                
//                 dp[i][val] = min(pick, notPick);
//             }
//         }
        
//         int ans = dp[n-1][amount];
//         return ans >= 1e9 ? -1 : ans;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // Tabulation Space optimised
        int n = coins.size();
        vector<int> dp(amount+1, 1e9);
        
        for(int t=0; t<=amount; t++){
            if(t%coins[0] == 0){
                dp[t] = t / coins[0];
            }
        }
        
        for(int i=1; i<n; i++){
            vector<int> temp(amount+1, 1e9);
            for(int val=0; val<=amount; val++){
                
                int notPick = dp[val];
                int pick = 1e9;
                if(coins[i] <= val){
                    pick = 1 + temp[val-coins[i]];
                }
                
                temp[val] = min(pick, notPick);
            }
            dp = temp;
        }
        
        int ans = dp[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};