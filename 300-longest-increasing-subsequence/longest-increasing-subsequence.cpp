// class Solution {
// public:
//     int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        
//         if(ind >= nums.size()){
//             return 0;
//         }
        
//         if(dp[ind][prev+1] != -1){
//             return dp[ind][prev+1];
//         }
        
//         int notPick = 0 + f(ind+1, prev, nums, dp);
//         int pick = 0;
        
//         if(prev == -1 || nums[ind] > nums[prev]){
//             pick = 1 + f(ind+1, ind, nums, dp);
//         }
        
//         return dp[ind][prev+1] = max(pick, notPick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
        
//         // Memoization
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
//         return f(0, -1, nums, dp);
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // Tabulation
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                
                int notPick = 0 + dp[i+1][prev+1];
                int pick = 0;
                
                if(prev == -1 || nums[i] > nums[prev]){
                    pick = 1 + dp[i+1][i+1];
                }
                
                dp[i][prev+1] = max(pick, notPick);
            }
        }
        return dp[0][0];
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // Tabulation - space optimised
        int n = nums.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            vector<int> curr(n+1, 0);
            for(int prev=i-1; prev>=-1; prev--){
                
                int notPick = 0 + dp[prev+1];
                int pick = 0;
                
                if(prev == -1 || nums[i] > nums[prev]){
                    pick = 1 + dp[i+1];
                }
                
                curr[prev+1] = max(pick, notPick);
            }
            dp = curr;
        }
        return dp[0];
    }
};
