class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        int n = boxGrid.size(), m = boxGrid[0].size();
        for(int row=0; row<n; row++) {
            int i=0, j=0;
            while(i < m && j < m) {
                if(boxGrid[row][j] == '.') {
                    swap(boxGrid[row][i], boxGrid[row][j]);
                    i++;
                    j++;
                }
                else if(boxGrid[row][j] == '*') {
                    i = j+1;
                    j = j+1;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<char>> ans(m, vector<char>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[j][n-1-i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};