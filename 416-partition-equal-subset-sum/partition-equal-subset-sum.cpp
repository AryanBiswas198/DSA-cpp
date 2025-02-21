class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Tabulation
        int n = nums.size(), sum = 0, k;
        if(n == 1) {
            return false;
        }

        for(auto it: nums) {
            sum += it;
        }

        if(sum % 2 == 1) {
            return false;
        }


        k = sum / 2;
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }

        if(nums[0] <= k) {
            dp[0][nums[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int target=1; target<=k; target++) {
                bool notPick = dp[i-1][target];
                bool pick = false;

                if(nums[i] <= target) {
                    pick = dp[i-1][target-nums[i]];
                }

                dp[i][target] = pick || notPick;
            }
        }
        return dp[n-1][k];
    }
};