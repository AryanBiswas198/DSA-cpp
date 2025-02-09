class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row<0 || col<0 || row>=n || col>=m) {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<char>>& board, vector<vector<bool>> &vis, queue<pair<int, int>> &q) {
        int n = board.size(), m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            int row = top.first, col = top.second;
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i], ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;

        for(int row=0; row<n; row++) {
            if(board[row][0] == 'O') {
                q.push({row, 0});
                vis[row][0] = true;
            }
            if(board[row][m-1] == 'O') {
                q.push({row, m-1});
                vis[row][m-1] = true;
            }
        }

        for(int col=0; col<m; col++) {
            if(board[0][col] == 'O') {
                q.push({0, col});
                vis[0][col] = true;
            }

            if(board[n-1][col] == 'O') {
                q.push({n-1, col});
                vis[n-1][col] = true;
            }
        }

        bfs(board, vis, q);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};