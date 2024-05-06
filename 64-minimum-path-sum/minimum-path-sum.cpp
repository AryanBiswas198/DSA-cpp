class Solution {
public:
    int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid){
        
        if(row < 0 || col < 0){
            return 1e9;
        }
        
        if(row == 0 && col == 0){
            return grid[0][0];
        }
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int left = grid[row][col] + f(row, col-1, dp, grid);
        int up = grid[row][col] + f(row-1, col, dp, grid);
        
        return dp[row][col] = min(left, up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        // Memoization
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n-1, m-1, dp, grid);
    }
};