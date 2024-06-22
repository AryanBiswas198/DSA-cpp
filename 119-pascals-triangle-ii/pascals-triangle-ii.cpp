class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
//         // Brute Force
//         vector<vector<int>> arr(rowIndex+1);
//         vector<int> ans;
        
//         for(int i=0; i<=rowIndex; i++){
//             arr[i].resize(i+1);
//             arr[i][0] = arr[i][i] = 1;
            
//             for(int j=1; j<i; j++){
//                 arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//             }
//         }
        
//         for(int i=0; i<=rowIndex; i++){
//             ans.push_back(arr[rowIndex][i]);
//         }
//         return ans;
        
        
        //************** Optimal Approach *****************
        long long ans = 1;
        vector<int> arr;
        arr.push_back(ans);
        
        for(int i=1; i<=rowIndex; i++){
            ans = ans*(rowIndex+1-i);
            ans = ans/i;
            arr.push_back(ans);
        }
        return arr;
    }
};