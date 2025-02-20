class Solution {
public:
    int findSteps(int n, vector<int> &dp) {
        
        if(n < 0) {
            return 0;
        }

        if(n == 0) {
            return 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = findSteps(n-1, dp) + findSteps(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return findSteps(n, dp);
    }
};