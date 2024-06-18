class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, int> mpp;
        vector<int> ans(2, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[grid[i][j]]++;
            }
        }
        
        for(int i=1; i<=n*n; i++){
            if(mpp[i] == 0){
                ans[1] = i;
            }
            
            if(mpp[i] == 2){
                ans[0] = i;
            }
        }
        return ans;
    }
};