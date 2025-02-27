class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0;
        map<vector<int>, int> mpp;

        for(int i=0; i<n; i++) {
            mpp[grid[i]]++;
        }

        for(int i=0; i<n; i++) {
            vector<int> arr;
            for(int j=0; j<n; j++) {
                arr.push_back(grid[j][i]);
            }
            cnt += mpp[arr];
        }
        return cnt;
    }
};