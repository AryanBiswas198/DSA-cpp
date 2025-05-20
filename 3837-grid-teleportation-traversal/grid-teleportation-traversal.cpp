class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    int minMoves(vector<string>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portals;
        unordered_set<char> usedPortals;
        deque<pair<int, pair<int, int>>> dq;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') {
                    portals[matrix[i][j]].push_back({i, j});
                }
            }
        }

        dq.push_front({0, {0, 0}});
        dist[0][0] = 0;

        while(!dq.empty()) {
            auto frontele = dq.front();
            dq.pop_front();
            
            int time = frontele.first, row = frontele.second.first, col = frontele.second.second;

            if(dist[row][col] < time) {
                continue;
            }

            char ch = matrix[row][col];
            if((ch >= 'A' && ch <= 'Z') && usedPortals.find(ch) == usedPortals.end()) {
                for(auto it: portals[ch]) {
                    int r = it.first, c = it.second;
                    if(r == row && c == col) continue;
                    if(dist[r][c] > time) {
                        dist[r][c] = time;
                        dq.push_front({time, {r, c}});
                    }
                }
                usedPortals.insert(ch);
            }
            
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(isValid(nrow, ncol, n, m) && matrix[nrow][ncol] != '#') {
                    if(dist[nrow][ncol] > time + 1) {
                        dist[nrow][ncol] = time + 1;
                        dq.push_back({time+1, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};