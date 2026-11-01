class Solution {
public:
    bool isAtEdge(int i, int j, int n, int m) {
        if(i == 0 || j == 0 || i == n-1 || j == m-1) {
            return true;
        }
        return false;
    }

    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n-1 || col >= m-1) {
            return false;
        }
        return true;
    }

    void bfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q) {

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int n = grid.size(), m = grid[0].size();

        grid[i][j] = 1;
        q.push({i, j});

        while(!q.empty()) {
            auto topEle = q.front();
            q.pop();

            int row = topEle.first, col = topEle.second;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i], ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 1;
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isAtEdge(i, j, n, m) && grid[i][j] == 0) {
                    bfs(i, j, grid, q);
                }
            }
        }

        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    count++;
                    bfs(i, j, grid, q);
                }
            }
        }
        return count;
    }
};