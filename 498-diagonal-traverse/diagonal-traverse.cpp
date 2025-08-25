class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<vector<int>> vec;
        int n = mat.size(), m = mat[0].size(), cnt = 0;

        for(int col=0; col<m; col++) {
            int i = 0, j = col;
            vector<int> temp;
            while(i < n && j >= 0) {
                temp.push_back(mat[i++][j--]);
            }
            if(cnt % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            vec.push_back(temp);
            cnt++;
        }

        for(int row=1; row<n; row++) {
            int i = row, j = m-1;
            vector<int> temp;
            while(i < n && j >= 0) {
                temp.push_back(mat[i++][j--]);
            }
            if(cnt % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            vec.push_back(temp);
            cnt++;
        }

        vector<int> ans;
        for(auto temp: vec) {
            for(auto it: temp) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};