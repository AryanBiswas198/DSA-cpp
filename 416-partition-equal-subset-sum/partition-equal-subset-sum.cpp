class Solution {
public:
    bool checkIf(int ind, int target, vector<vector<int>> &dp, vector<int> &nums) {
        if(target == 0) {
            return true;
        }

        if(ind == 0) {
            return target == nums[ind];
        }

        if(dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int notPick = checkIf(ind-1, target, dp, nums);
        int pick = false;
        if(nums[ind] <= target) {
            pick = checkIf(ind-1, target-nums[ind], dp, nums);
        }

        return dp[ind][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        // Memoization
        int n = nums.size(), sum = 0, k;
        if(n == 1) {
            return false;
        }

        for(auto it: nums) {
            sum += it;
        }

        k = sum / 2;

        if(sum % 2 == 1) {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return checkIf(n-1, k, dp, nums);
    }
};