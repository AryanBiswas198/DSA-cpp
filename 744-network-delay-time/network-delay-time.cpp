class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, list<vector<int>>> adj;
        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int dis = front.first, node = front.second;

            for(auto it: adj[node]) {
                int adjNode = it[0], adjTime = it[1];
                if(dis + adjTime < dist[adjNode]) {
                    dist[adjNode] = dis + adjTime;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i] >= 1e9) {
                return -1;
            }
            else{
                maxTime = max(maxTime, dist[i]);
            }
        }
        return maxTime;
    }
};