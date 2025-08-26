class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int n = dimensions.size(), maxDiagonalLen = 0, maxArea = 0;
        for(int i=0; i<n; i++) {
            int len = dimensions[i][0], wid = dimensions[i][1];
            int diagonalLen = len*len + wid*wid, area = len * wid;

            if(diagonalLen > maxDiagonalLen || (diagonalLen == maxDiagonalLen && area > maxArea)) {
                maxDiagonalLen = diagonalLen;
                maxArea = area;
            }
        }
        return maxArea;
    }
};