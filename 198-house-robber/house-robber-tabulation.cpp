class Solution {
public:
    int rob(vector<int>& nums) {
        
        // Tabulation
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n+1, -1);
        
        dp[0] = nums[0];
        dp[1] = 0;
        
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1){
                pick = nums[i] + dp[i-2];
            }
            int notPick = dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
};
