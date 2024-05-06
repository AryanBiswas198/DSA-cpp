// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid){
        
//         if(row < 0 || col < 0){
//             return 1e9;
//         }
        
//         if(row == 0 && col == 0){
//             return grid[0][0];
//         }
        
//         if(dp[row][col] != -1){
//             return dp[row][col];
//         }
        
//         int left = grid[row][col] + f(row, col-1, dp, grid);
//         int up = grid[row][col] + f(row-1, col, dp, grid);
        
//         return dp[row][col] = min(left, up);
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
        
//         // Memoization
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
        
//         return f(n-1, m-1, dp, grid);
//     }
// };


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//         // Tabulation
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, 1e9));
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(i==0 && j==0){
//                     dp[0][0] = grid[0][0];
//                 }
//                 else{
//                     int up = 1e9, left = 1e9;
//                     if(i > 0){
//                         up = grid[i][j] + dp[i-1][j];
//                     }
                    
//                     if(j > 0){
//                         left = grid[i][j] + dp[i][j-1];
//                     }
                    
//                     dp[i][j] = min(left, up);
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // Tabulation Space optimised
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 1e9);
        
        for(int i=0; i<n; i++){
            vector<int> temp(m, 1e9);
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    temp[j] = grid[i][j];
                }
                else{
                    int left = 1e9, up = 1e9;
                    if(j > 0){
                        left = grid[i][j] + temp[j-1];
                    }
                    
                    if(i > 0){
                        up = grid[i][j] + dp[j];
                    }
                    
                    temp[j] = min(left, up);
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
};