class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), sum = 0;

        for(int i=0; i<n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        for(int j=m-1; j>=0; j--) {
            int maxi = INT_MIN;
            for(int i=0; i<n; i++) {
                maxi = max(maxi, grid[i][j]);
            }
            sum += maxi;
        }
        return sum;
    }
};