class Solution {
public:
    int findPathSum(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        if(row < 0 || col < 0) {
            return 1e9;
        }

        if(row == 0 && col == 0) {
            return grid[row][col];
        }

        if(dp[row][col] != 1e9) {
            return dp[row][col];
        }

        int left = findPathSum(row, col-1, dp, grid) + grid[row][col];
        int up = findPathSum(row-1, col, dp, grid) + grid[row][col];

        return dp[row][col] = min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        // Memoization
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        return findPathSum(n-1, m-1, dp, grid);
    }
};