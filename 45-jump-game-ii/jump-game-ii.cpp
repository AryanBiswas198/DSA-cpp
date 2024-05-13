class Solution {
public:
    int f(int ind, int n, vector<int> &nums, vector<int> &dp){
        
        if(ind == n-1){
            return 0;
        }
        
        // if(ind >= n){
        //     return 1e9;
        // }
        
        if(dp[ind] != 1e9){
            return dp[ind];
        }
        
        int mini = 1e9;
        
        for(int i=1; i<=nums[ind] && ind+i<n; i++){
            mini = min(mini, 1 + f(ind+i, n, nums, dp));
        }
        
        return dp[ind] = mini;
    }
    
    int jump(vector<int>& nums) {
        
        // Memeoization
        int n = nums.size();
        vector<int> dp(n, 1e9);
        
        return f(0, n, nums, dp);
    }
};