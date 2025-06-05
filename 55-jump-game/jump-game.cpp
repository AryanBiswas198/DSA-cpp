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
        
        // Tabulation
        int n = nums.size();
        vector<int> dp(n, 0); 
        dp[n-1] = true;

        for(int i=n-2; i>=0; i--) {
            for(int j=1; j<=nums[i] && i+j<n; j++) {
                if(dp[i+j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};