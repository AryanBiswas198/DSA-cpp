class Solution {
public:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        
        if(ind == 0){
            if(target == 0 && nums[ind] == 0){
                return 2;
            }
            else if(target == 0 || nums[ind] == target){
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        int notPick = f(ind-1, target, nums, dp);
        int pick = 0;
        
        if(nums[ind] <= target){
            pick = f(ind-1, target-nums[ind], nums, dp);
        }
        
        return dp[ind][target] = pick + notPick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // Memoization
        int n = nums.size(), totalSum = 0;
        for(auto it: nums){
            totalSum += it;
        }
        
        if(totalSum - target < 0 || (totalSum-target)%2 != 0){
            return 0;
        }
        
        int k = (totalSum - target)/2;
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1, k, nums, dp);
    }
};