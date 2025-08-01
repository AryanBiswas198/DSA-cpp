class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), freshCnt = 0, cnt = 0, maxTime = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
                else if(grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();

                int time = front.first, row = front.second.first, col = front.second.second;

                maxTime = max(maxTime, time);

                for(int i=0; i<4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = true;
                        q.push({time+1, {nrow, ncol}});
                        cnt++;
                    }
                }
            }
        }

        if(freshCnt != cnt) {
            return -1;
        }
        return maxTime;
    }
};