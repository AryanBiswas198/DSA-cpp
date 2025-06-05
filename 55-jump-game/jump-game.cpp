class Solution {
public:
    bool f(int ind, vector<int> &dp, vector<int> &nums) {
        if(ind == nums.size()-1) {
            return true;
        }

        if(ind >= nums.size()) {
            return false;
        }

        if(dp[ind] != -1) {
            return dp[ind];
        }

        for(int i=1; i<=nums[ind]; i++) {
            if(f(ind+i, dp, nums)) {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        
        // Memoization
        int n = nums.size();
        vector<int> dp(n, -1); 

        return f(0, dp, nums);
    }
};