class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(col == grid[0].size()-1) {
            return 0;
        }

        if(dp[row][col] != - 1) {
            return dp[row][col];
        }

        int direction[] = {-1, 0, 1};
        int maxi = 0;

        for(auto dir: direction) {
            int nrow = row + dir;
            int ncol = col + 1;

            if(nrow >= 0 && nrow < grid.size() && grid[nrow][ncol] > grid[row][col]) {
                maxi = max(maxi, 1 + f(nrow, ncol, grid, dp));
            }
        }
        return dp[row][col] = maxi;
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0; i<n; i++) {
            ans = max(ans, f(i, 0, grid, dp));
        }
        return ans;
    }
};