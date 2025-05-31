class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] == 1) {
            return -1;
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});

        dist[0][0] = 1;

        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int dis = front.first, row = front.second.first, col = front.second.second;

            if(row == n-1 && col == m-1) {
                return dis;
            }

            for(int r=-1; r<=1; r++) {
                for(int c=-1; c<=1; c++) {
                    int nrow = row + r;
                    int ncol = col + c;

                    if(isValid(nrow, ncol, n, m) && dis + 1 < dist[nrow][ncol] && grid[nrow][ncol] == 0) {
                        dist[nrow][ncol] = dis + 1;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};