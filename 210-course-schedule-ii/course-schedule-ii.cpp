class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adjList;
        vector<int> inorder(numCourses, 0);
        queue<int> q;
        vector<int> ans;

        for(auto it: prerequisites) {
            adjList[it[0]].push_back(it[1]);
            inorder[it[1]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(inorder[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto adjNode: adjList[node]) {
                inorder[adjNode]--;
                if(inorder[adjNode] == 0) {
                    q.push(adjNode);
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