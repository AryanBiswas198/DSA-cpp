class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, pair<int, int>>> q;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int dis = front.first, row = front.second.first, col = front.second.second;

            ans[row][col] = dis;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && mat[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        return ans;
    }
};