class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(auto nbr: adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return cnt == numCourses;

    }
};