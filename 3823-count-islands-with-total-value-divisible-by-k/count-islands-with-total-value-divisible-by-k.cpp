class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    void bfs(int row, int col, int k, vector<vector<bool>> &vis, vector<vector<int>> &grid, int &cnt) {

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;
        long long sum = 0, n = grid.size(), m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int r = front.first, c = front.second;
            sum += grid[r][c];

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] > 0 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
        if(sum % k == 0) {
            cnt++;
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    bfs(i, j, k, vis, grid, cnt);
                }
            }
        }
        return cnt;
    }
};