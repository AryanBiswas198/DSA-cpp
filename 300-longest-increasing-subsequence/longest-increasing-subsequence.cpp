class Solution {
public:
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        
        if(ind >= nums.size()){
            return 0;
        }
        
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        
        int notPick = 0 + f(ind+1, prev, nums, dp);
        int pick = 0;
        
        if(prev == -1 || nums[ind] > nums[prev]){
            pick = 1 + f(ind+1, ind, nums, dp);
        }
        
        return dp[ind][prev+1] = max(pick, notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        // Memoization
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return f(0, -1, nums, dp);
    }
};