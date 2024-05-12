class Solution {
public:
    bool f(int ind, int n, vector<int> &nums, vector<int> &dp){
        
        if(ind == n-1){
            return true;
        }
        
        if(ind >= n){
            return false;
        }
        
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        for(int i=1; i<=nums[ind] && ind+i<n; i++){
            if(f(ind+i, n, nums, dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        // Memoization
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(0, n, nums, dp);
    }
};