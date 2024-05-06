class Solution {
public:
    int f(vector<int> nums){
        
        int n = nums.size();
        vector<int> dp(n, -1);
        
        dp[0] = nums[0], dp[1] = 0;
        
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1){
                pick = nums[i] + dp[i-2];
            }
            int notPick = 0 + dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        
        // Tabulation - as memoization doesn't works
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(n, -1);
        vector<int> temp1, temp2;
        
         for(int i=0; i<n; i++){
             if(i!=0) temp1.push_back(nums[i]);
             
             if(i!=n-1) temp2.push_back(nums[i]);
         }
        
        return max(f(temp1), f(temp2));
    }
};