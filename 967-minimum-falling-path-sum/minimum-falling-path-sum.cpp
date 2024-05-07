// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        
//         if(col < 0 || col >= matrix.size()){
//             return 1e9;
//         }
        
//         if(row == 0){
//             return matrix[row][col];
//         }
        
//         if(dp[row][col] != 1e9){
//             return dp[row][col];
//         }
        
//         int up = matrix[row][col] + f(row-1, col, dp, matrix);
//         int upLeft = matrix[row][col] + f(row-1, col-1, dp, matrix);
//         int upRight = matrix[row][col] + f(row-1, col+1, dp, matrix);
        
//         return dp[row][col] = min(up, min(upLeft, upRight));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         // Memoization
//         int n = matrix.size(), m = matrix[0].size();
        
//         vector<vector<int>> dp(n, vector<int>(m, 1e9));
//         int mini = 1e9;
        
//         for(int j=0; j<m; j++){
//             mini = min(mini, f(n-1, j, dp, matrix));
//         }
//         return mini;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // Tabulation
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int up = matrix[i][j], upLeft = 1e9, upRight = 1e9;
                up += dp[i-1][j];
                
                if(j-1>=0){
                    upLeft = matrix[i][j] + dp[i-1][j-1];
                }
                
                if(j+1<m){
                    upRight = matrix[i][j] + dp[i-1][j+1];
                }
                
                dp[i][j] = min(up, min(upLeft, upRight));
            }
        }
        
        int mini = INT_MAX;
        
        for(int j=0; j<m; j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};