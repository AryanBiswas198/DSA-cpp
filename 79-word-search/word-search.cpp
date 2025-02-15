class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    bool dfs(int row, int col, int cnt, vector<vector<char>>& board, string word) {
        if(cnt >= word.size()) {
            return true;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int n = board.size(), m = board[0].size();

        char original = board[row][col];
        board[row][col] = '$';

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow, ncol, n, m) && board[nrow][ncol] == word[cnt]) {
                if(dfs(nrow, ncol, cnt+1, board, word)) {
                    return true;
                }
            }
        }
        board[row][col] = original;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};