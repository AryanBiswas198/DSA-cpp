// class Solution {
// public:
//     int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &triangle){
        
//         if(row == triangle.size()-1){
//             return triangle[row][col];
//         }
        
//         if(dp[row][col] != 1e9){
//             return dp[row][col];
//         }
        
//         int down = triangle[row][col] + f(row+1, col, dp, triangle);
//         int downRight = triangle[row][col] + f(row+1, col+1, dp, triangle);
        
//         return dp[row][col] = min(down, downRight);
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         // Memoization
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, 1e9));
        
//         return f(0, 0, dp, triangle);
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // Tabulation
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                int down = triangle[i][j] + dp[i+1][j];
                int downRight = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, downRight);
            }
        }
        
        return dp[0][0];
    }
};



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // Tabulation - Space Optimised
        int n = triangle.size();
        vector<int> dp(n, 1e9);
        
        for(int j=0; j<n; j++){
            dp[j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--){
            vector<int> temp(n, 1e9);
            for(int j=i; j>=0; j--){
                
                int down = triangle[i][j] + dp[j];
                int downRight = triangle[i][j] + dp[j+1];
                
                temp[j] = min(down, downRight);
            }
            dp = temp;
        }
        
        return dp[0];
    }
};
