class Solution {
public:
    int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        
        if(col < 0 || col >= matrix.size()){
            return 1e9;
        }
        
        if(row == 0){
            return matrix[row][col];
        }
        
        if(dp[row][col] != 1e9){
            return dp[row][col];
        }
        
        int up = matrix[row][col] + f(row-1, col, dp, matrix);
        int upLeft = matrix[row][col] + f(row-1, col-1, dp, matrix);
        int upRight = matrix[row][col] + f(row-1, col+1, dp, matrix);
        
        return dp[row][col] = min(up, min(upLeft, upRight));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // Memoization
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        int mini = 1e9;
        
        for(int j=0; j<m; j++){
            mini = min(mini, f(n-1, j, dp, matrix));
        }
        return mini;
    }
};