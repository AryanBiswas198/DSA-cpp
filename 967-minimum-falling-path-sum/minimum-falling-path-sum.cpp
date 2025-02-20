class Solution {
public:
    int findMini(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &matrix) {
        if(col < 0 || col >= matrix.size()) {
            return 1e9;
        }
        if(row == 0) {
            return matrix[row][col];
        }

        if(dp[row][col] != 1e9) {
            return dp[row][col];
        }

        int mini = 1e9;
        for(int j=-1; j<=1; j++) {
            mini = min(mini, findMini(row-1, col+j, dp, matrix) + matrix[row][col]);
        }
        
        return dp[row][col] = mini;

        // int downLeft = findMini(row-1, col-1, dp, matrix) + matrix[row][col];
        // int down = findMini(row-1, col, dp, matrix) + matrix[row][col];
        // int downRight = findMini(row-1, col+1, dp, matrix) + matrix[row][col];

        // return dp[row][col] = min(downLeft, min(down, downRight));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Memoization
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        int mini = 1e9;

        for(int j=0; j<m; j++) {
            mini = min(mini, findMini(n-1, j, dp, matrix));
        }
        return mini;
    }
};