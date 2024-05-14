class Solution {
public:
    bool isValid(int row, int col, int n, int m){
        if(row<0 || col<0 || row>=n || col>=m){
            return false;
        }
        return true;
    }
    
    int f(int row, int col, vector<vector<int>> &grid){
        
        int n = grid.size(), m = grid[0].size(), currVal = grid[row][col], maxVal = 0;
        grid[row][col] = 0;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i], ncol = col + dcol[i];
            if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] != 0){
                maxVal = max(maxVal, f(nrow, ncol, grid));
            }
        }
        grid[row][col] = currVal;
        return currVal + maxVal;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), maxi = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    maxi = max(maxi, f(i, j, grid));
                }
            }
        }
        return maxi;
    }
};