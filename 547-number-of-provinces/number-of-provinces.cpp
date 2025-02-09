class Solution {
public:
    void dfs(int ele, vector<bool> &vis, unordered_map<int, vector<int>> &adj) {
        for(auto it: adj[ele]) {
            if(!vis[it]) {
                vis[it] = true;
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};