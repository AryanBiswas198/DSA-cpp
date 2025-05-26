class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> newVec = image;
        int n = newVec.size(), m = newVec[0].size(), originalColor = newVec[sr][sc];

        if(color == originalColor) {
            return newVec;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        newVec[sr][sc] = color;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int row = front.first, col = front.second;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(isValid(nrow, ncol, n, m) && newVec[nrow][ncol] == originalColor) {
                    newVec[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return newVec;
    }
};