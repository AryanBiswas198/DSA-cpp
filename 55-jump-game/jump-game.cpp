class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // Tabulation
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[n-1] = true;
        
        for(int ind=n-2; ind>=0; ind--){
            for(int i=1; i<=nums[ind] && ind+i<n; i++){
                if(dp[ind+i] == true){
                    dp[ind] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};