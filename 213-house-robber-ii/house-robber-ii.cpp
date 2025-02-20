class Solution {
public:
// Tabulation
    int findMax(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i=1; i<n; i++) {
            int notPick = 0 + dp[i-1];
            int pick = nums[i];
            if(i > 1) {
                pick += dp[i-2];
            }
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> temp1, temp2;
        for(int i=0; i<n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(findMax(temp1), findMax(temp2));
    }
};