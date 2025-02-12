class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, list<vector<int>>> adj;
        for(auto it: flights) {
            int u = it[0], v = it[1], w = it[2];\
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, src}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int stops = top.first, dis = top.second.first, node = top.second.second;
            if(stops > k) {
                continue;
            }

            for(auto it: adj[node]) {
                int adjNode = it[0], edgeW = it[1];
                if(dis + edgeW < dist[adjNode]) {
                    dist[adjNode] = dis + edgeW;
                    pq.push({stops+1, {dist[adjNode], adjNode}});
                }
            }
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};