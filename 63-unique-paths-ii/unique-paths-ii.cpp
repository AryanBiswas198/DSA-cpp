class Solution {
public:
    int findUniquePaths(int row, int col, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid) {
        if(row < 0 || col < 0 || obstacleGrid[row][col] == 1) {
            return 0;
        }

        if(row == 0 && col == 0) {
            return 1;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int left = findUniquePaths(row, col-1, dp, obstacleGrid);
        int up = findUniquePaths(row-1, col, dp, obstacleGrid);

        return dp[row][col] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Memoization
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(obstacleGrid[i][j] == 1) {
                    continue;
                }
                else{
                    int left = 0, up = 0;
                    if(i > 0) {
                        up += dp[i-1][j];
                    }

                    if(j > 0) {
                        left += dp[i][j-1];
                    }

                    dp[i][j] = left + up;
                }
            }
        }
        return dp[n-1][m-1];
    }
};