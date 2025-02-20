class Solution {
public:
    int findMini(int row, int col, vector<vector<int>> &dp, vector<vector<int>>& triangle) {
        if(row == triangle.size()-1) {
            return triangle[row][col];
        }
        if(col > triangle.size()-1) {
            return 1e9;
        }

        if(dp[row][col] != 1e9) {
            return dp[row][col];
        }

        int down = triangle[row][col] + findMini(row+1, col, dp, triangle);
        int downRight = triangle[row][col] + findMini(row+1, col+1, dp, triangle);

        return dp[row][col] = min(down, downRight);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // Tabulation
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++) {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int downRight = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, downRight);
            }
        }
        return dp[0][0];
    }
};