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
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return findUniquePaths(n-1, m-1, dp, obstacleGrid);
    }
};