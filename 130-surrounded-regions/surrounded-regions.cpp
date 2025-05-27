class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }


    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& board) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[row][col] = true;

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow, ncol, board.size(), board[0].size()) && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O' && !vis[i][j]) {
                    dfs(i, j, vis, board);
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int row = front.first, col = front.second;
            if(vis[row][col] == true) {
                continue;
            }
            board[row][col] = 'X';
            vis[row][col] = true;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                }
            }
        }
    }
};