class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        unordered_map<int, list<vector<int>>> adj;

        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        dist[src] = 0;
        pq.push({0, {0, src}});

        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int stop = front.first, dis = front.second.first, node = front.second.second;

            if(stop > k) {
                continue;
            }

            for(auto it: adj[node]) {
                int adjNode = it[0], adjDis = it[1];
                if(dis + adjDis < dist[adjNode]) {
                    dist[adjNode] = dis + adjDis;
                    pq.push({stop+1, {dist[adjNode], adjNode}});
                }
            }
        }
        return dist[dst] >= 1e9 ? -1 : dist[dst];
    }
};