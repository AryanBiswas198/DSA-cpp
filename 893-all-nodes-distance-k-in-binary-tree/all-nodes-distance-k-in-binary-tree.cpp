/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParent(TreeNode *root, map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()) {
            auto sz = q.size();
            while(sz--) {
                auto frontNode = q.front();
                q.pop();

                if(frontNode->left != NULL) {
                    q.push(frontNode->left);
                    parent[frontNode->left] = frontNode;
                }
                if(frontNode->right != NULL) {
                    q.push(frontNode->right);
                    parent[frontNode->right] = frontNode;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        int dis = 0;
        vector<int> ans;
        queue<TreeNode*> q;
        map<TreeNode*, bool> vis;
        map<TreeNode*, TreeNode*> parent;

        q.push(target);
        mapParent(root, parent);
        vis[target] = true;

        while(!q.empty()) {
            auto sz = q.size();
            while(sz--) {
                auto frontNode = q.front();
                q.pop();

                if(dis == k) {
                    ans.push_back(frontNode->val);
                }

                if(frontNode->left != NULL && !vis[frontNode->left]) {
                    q.push(frontNode->left);
                    vis[frontNode->left] = true;
                }

                if(frontNode->right != NULL && !vis[frontNode->right]) {
                    q.push(frontNode->right);
                    vis[frontNode->right] = true;
                }

                if(parent[frontNode] != NULL && !vis[parent[frontNode]]) {
                    q.push(parent[frontNode]);
                    vis[parent[frontNode]] = true;
                }
            }
            dis++;
        }
        return ans;
    }
};