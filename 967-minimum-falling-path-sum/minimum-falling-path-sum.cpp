class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Tabulation
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for(int j=0; j<n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int down = matrix[i][j] + dp[i-1][j];
                int downLeft = 1e9, downRight = 1e9;
                if(j-1 >= 0) {
                    downLeft = matrix[i][j] + dp[i-1][j-1];
                }

                if(j+1<n) {
                    downRight = matrix[i][j] + dp[i-1][j+1];
                }

                dp[i][j] = min(down, min(downLeft, downRight));
            }
        }
        
        int mini = 1e9;
        for(int j=0; j<n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};