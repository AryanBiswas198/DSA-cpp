class Solution {
public:
    bool findAns(vector<vector<char>> &mat, char win) {
        // Diagonal Check
        if((mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[1][1] == win) || (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[1][1] == win)) {
            return true;
        }

        // Row and column check
        for(int i=0; i<3; i++) {
            if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] == win) {
                return true;
            }

            if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i] && mat[0][i] == win) {
                return true;
            }
        }
        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        
        int n = moves.size();
        vector<vector<char>> mat(3, vector<char>(3, ' '));

        for(int i=0; i<n; i++) {
            int row = moves[i][0], col = moves[i][1];
            if(i % 2 == 0) {
                mat[row][col] = 'X';
            }
            else{
                mat[row][col] = 'O';
            }
        }

        if(findAns(mat, 'X')) return "A";
        if(findAns(mat, 'O')) return "B";
        if(moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};