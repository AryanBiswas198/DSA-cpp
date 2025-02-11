class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row<0 || col<0 || row>=n || col>=m) {
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int dis = top.first, row = top.second.first, col = top.second.second;
            if(row == n-1 && col == m-1) {
                return dis;
            }

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(isValid(nrow, ncol, n, m)) {
                    int maxEffort = max(abs(heights[nrow][ncol] - heights[row][col]), dis);
                    if(maxEffort < dist[nrow][ncol]) {
                        pq.push({maxEffort, {nrow, ncol}});
                        dist[nrow][ncol] = maxEffort;
                    }
                }
            }
        }
        return -1;
    }
};