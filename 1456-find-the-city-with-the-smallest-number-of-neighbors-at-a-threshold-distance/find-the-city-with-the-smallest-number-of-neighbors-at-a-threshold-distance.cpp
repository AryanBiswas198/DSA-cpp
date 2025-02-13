class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(auto it: edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u][v] = w;
            adj[v][u] = w;
        }

        for(int i=0; i<n; i++) {
            adj[i][i] = 0;
        }

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(adj[i][k] != INT_MAX || adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], (adj[i][k] + adj[k][j]));
                    }
                }
            }
        }

        int cityCnt = n, cityNo;;
        for(int city=0; city<n; city++) {
            int cnt = 0;
            for(int adjCity=0; adjCity<n; adjCity++) {
                if(adj[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }

            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};