class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size(), m = image[0].size(), originalColor = image[sr][sc];

        if(color == originalColor) {
            return image;
        }

        vector<vector<int>> ans = image;
        ans[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int row = front.first, col = front.second;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && ans[nrow][ncol] == originalColor) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};