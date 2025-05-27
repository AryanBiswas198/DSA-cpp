class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row<0 || col<0 || row>=n || col>=m) {
            return false;
        } 
        return true;
    }

    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid) {

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int row = front.first, col = front.second;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, grid.size(), grid[0].size()) && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, vis, grid);
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};