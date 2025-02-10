class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        vector<int> ans;

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

            ans.push_back(element);

            for(auto it: adj[element]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(ans.size() == numCourses) {
            reverse(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }
};