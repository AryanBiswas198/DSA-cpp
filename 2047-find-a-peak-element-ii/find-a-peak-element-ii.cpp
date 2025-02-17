// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        // Brute Force 
//         int n = mat.size(), m = mat[0].size(), maxi = INT_MIN, maxRow = 0, maxCol = 0;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(mat[i][j] > maxi) {
//                     maxi = mat[i][j];
//                     maxRow = i;
//                     maxCol = j;
//                 }
//             }
//         }
//         return {maxRow, maxCol};
//     }
// };

class Solution {
public:
    int findMaxRow(int mid, vector<vector<int>>& mat) { 
        int maxi = INT_MIN, index = 0;
        for(int i=0; i<mat.size(); i++) {
            if(mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int maxRowEle = findMaxRow(mid, mat);
            int left = mid-1 >= 0 ? mat[maxRowEle][mid-1] : -1;
            int right = mid+1 < m ? mat[maxRowEle][mid+1] : -1;

            if(mat[maxRowEle][mid] > left && mat[maxRowEle][mid] > right) {
                return {maxRowEle, mid};
            }
            else if(mat[maxRowEle][mid] < left) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {};
    }
};