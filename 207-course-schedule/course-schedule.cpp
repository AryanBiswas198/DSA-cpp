class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        int cnt = 0;

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int element = q.front();
            q.pop();

            cnt++;

            for(auto it: adj[element]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt == numCourses;
    }
};