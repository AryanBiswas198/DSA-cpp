class Solution {
public:
    bool checkBipartite(int node, int color, vector<bool> &vis, vector<int> &col, vector<vector<int>>& graph) {
        vis[node] = true;
        col[node] = color;

        for(auto it: graph[node]) {
            if(!vis[it]) {
                if(checkBipartite(it, !color, vis, col, graph) == false) {
                    return false;
                }
            }
            else if(col[it] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> col(n, -1);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(checkBipartite(i, 0, vis, col, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};