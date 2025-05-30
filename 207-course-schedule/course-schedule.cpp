class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(auto it: prerequisites) {
            adjList[it[0]].push_back(it[1]);
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

            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        return cnt == numCourses;
    }
};