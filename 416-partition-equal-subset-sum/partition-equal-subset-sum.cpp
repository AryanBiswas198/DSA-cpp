class Solution {
public:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        
        if(target == 0){
            return true;
        }
        
        if(ind == 0){
            return nums[0] == target;
        }
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        int notPick = f(ind-1, target, nums, dp);
        int pick = false;
        
        if(nums[ind] <= target){
            pick = f(ind-1, target-nums[ind], nums, dp);
        }
        
        return dp[ind][target] = pick || notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        // Memoization
        int n = nums.size(), totalSum = 0;
        
        for(auto it: nums){
            totalSum += it;
        }
        
        if(totalSum % 2 == 1){
            return false;
        }
        
        int k = totalSum / 2;
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        return f(n-1, k, nums, dp);
    }
};