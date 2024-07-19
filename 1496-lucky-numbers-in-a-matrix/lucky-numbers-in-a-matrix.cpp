class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
//         3  7  8
//         9  11 13
//         15 16 17
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> minRow(n, 1e9);
        vector<int> maxCol(m, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                minRow[i] = min(matrix[i][j], minRow[i]);
                maxCol[j] = max(matrix[i][j], maxCol[j]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
        
    }
};