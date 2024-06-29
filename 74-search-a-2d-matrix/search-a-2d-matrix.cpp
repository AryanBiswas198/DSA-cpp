// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         // Brute Force - TC: O(n^2). SC: O(1)
//         int n = matrix.size(), m = matrix[0].size();
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool searchEle(vector<int> matrix, int target){
        
        int low = 0, high = matrix.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid] == target){
                return true;
            }
            else if(matrix[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Optimal Approach. TC: O(n + log(m)) SC: O(1)
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){
                return searchEle(matrix[i], target);
            }
        }
        return false;
    }
};