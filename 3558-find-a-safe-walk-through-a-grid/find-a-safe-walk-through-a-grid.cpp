class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> maxHealth(n, vector<int>(m, -1));

        pq.push({health-grid[0][0], {0, 0}});
        maxHealth[0][0] = health - grid[0][0];

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int remHealth = top.first, row = top.second.first, col = top.second.second;

            if(remHealth <= 0) {
                continue;
            }

            if(row == n-1 && col == m-1) {
                return remHealth > 0;
            }

            if(remHealth < maxHealth[row][col]) {
                continue;
            }

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m)) {
                    int newHealth = remHealth - grid[nrow][ncol];

                    if(newHealth > 0 && newHealth > maxHealth[nrow][ncol]) {
                        pq.push({newHealth, {nrow, ncol}});
                        maxHealth[nrow][ncol] = newHealth;
                    }
                }
            }
        }
        return false;
    }
};