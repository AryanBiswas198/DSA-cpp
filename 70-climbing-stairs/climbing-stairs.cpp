class Solution {
public:
    int climbStairs(int n) {
        // Tabulation: 
        vector<int> dp(n+1, -1);
        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; i++) {
            int oneStep = dp[i-1];
            int twoStep = dp[i-2];

            dp[i] = oneStep + twoStep;
        }
        return dp[n];
    }
};