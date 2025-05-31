class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = 1e9+7;
        unordered_map<long long, list<vector<long long>>> adj;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            long long dis = front.first, node = front.second;

            for(auto it: adj[node]) {
                long long adjNode = it[0], adjDis = it[1];
                if(dis + adjDis < dist[adjNode]) {
                    dist[adjNode] = dis + adjDis;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + adjDis == dist[adjNode]) {
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};