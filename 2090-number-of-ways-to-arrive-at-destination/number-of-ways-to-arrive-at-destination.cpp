class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<long long, list<vector<long long>>> adj;
        for(auto it: roads) {
            long long u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<int> ways(n, 0);
        ways[0] = 1;

        int mod = 1e9+7;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long dis = top.first, node = top.second;
            for(auto it: adj[node]) {
                long long adjNode = it[0], edgeW = it[1];
                if(dis + edgeW < dist[adjNode]) {
                    dist[adjNode] = dis + edgeW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edgeW == dist[adjNode]) {
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};