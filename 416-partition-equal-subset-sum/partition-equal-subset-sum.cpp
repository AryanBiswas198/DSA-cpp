// class Solution {
// public:
//     bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        
//         if(target == 0){
//             return true;
//         }
        
//         if(ind == 0){
//             return nums[0] == target;
//         }
        
//         if(dp[ind][target] != -1){
//             return dp[ind][target];
//         }
        
//         int notPick = f(ind-1, target, nums, dp);
//         int pick = false;
        
//         if(nums[ind] <= target){
//             pick = f(ind-1, target-nums[ind], nums, dp);
//         }
        
//         return dp[ind][target] = pick || notPick;
//     }
    
//     bool canPartition(vector<int>& nums) {
        
//         // Memoization
//         int n = nums.size(), totalSum = 0;
        
//         for(auto it: nums){
//             totalSum += it;
//         }
        
//         if(totalSum % 2 == 1){
//             return false;
//         }
        
//         int k = totalSum / 2;
        
//         vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
//         return f(n-1, k, nums, dp);
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        // Tabulation
        int n = nums.size(), totalSum = 0, k = 0;
        
        for(auto it: nums){
            totalSum += it;
        }
        
        if(totalSum % 2 == 1){
            return false;
        }
        
        k = totalSum / 2;
        
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
        
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(nums[0] <= k){
            dp[0][nums[0]] = true;
        }
        
        for(int i=1; i<n; i++){
            for(int target=1; target<=k; target++){
                
                bool notPick = dp[i-1][target];
                bool pick = false;
                if(nums[i] <= target){
                    pick = dp[i-1][target-nums[i]];
                }
                
                dp[i][target] = pick || notPick;
            }
        }
        return dp[n-1][k];
    }
};