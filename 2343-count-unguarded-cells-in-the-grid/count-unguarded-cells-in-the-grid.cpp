class Solution {
public:
    bool isValid(int row, int col, int m, int n) {
        if(row < 0 || col < 0 || row >= m || col >= n) {
            return false;
        }
        return true;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(auto it: guards) {
            vis[it[0]][it[1]] = 2;
        }

        for(auto it: walls) {
            vis[it[0]][it[1]] = 2;
        }

        queue<pair<int, pair<int, int>>> q;
        for(auto it: guards) {
            int row = it[0], col = it[1];
            q.push({1, {row-1, col}});
            q.push({2, {row, col+1}});
            q.push({3, {row+1, col}});
            q.push({4, {row, col-1}});
        }

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int dir = front.first, row = front.second.first, col = front.second.second;

            if(!isValid(row, col, m, n) || vis[row][col] == 2) continue;

            vis[row][col] = 1;

            if(dir == 1) {
                q.push({1, {row-1, col}});
            }
            else if(dir == 2) {
                q.push({2, {row, col+1}});
            }
            else if(dir == 3) {
                q.push({3, {row+1, col}});
            }
            else {
                q.push({4, {row, col-1}});
            }
        }

        int cnt = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};