class Solution {
public:
    int f(int row, int col, vector<vector<int>> &dp) {
        if(row < 0 || col < 0) {
            return 0;
        }

        if(row == 0 && col == 0) {
            return 1;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int left = f(row, col-1, dp);
        int up = f(row-1, col, dp);

        return dp[row][col] = left + up;
    }

    int uniquePaths(int m, int n) {
        // Tabulation
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int left = 0, up = 0;
                    if(j > 0) {
                        left += dp[i][j-1];
                    }

                    if(i > 0) {
                        up += dp[i-1][j];
                    }

                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};