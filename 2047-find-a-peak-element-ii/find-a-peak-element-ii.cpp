class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size(), maxi = INT_MIN, maxRow = 0, maxCol = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] > maxi) {
                    maxi = mat[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
        return {maxRow, maxCol};
    }
};