/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, vector<int>>> mpp;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();

                TreeNode *node = front.first;
                int hd = front.second.first, lvl = front.second.second;

                mpp[hd][lvl].push_back(node->val);

                if(node->left != NULL) {
                    q.push({node->left, {hd-1, lvl+1}});
                }

                if(node->right != NULL) {
                    q.push({node->right, {hd+1, lvl+1}});
                }

                sort(mpp[hd][lvl].begin(), mpp[hd][lvl].end());
            }
        }

        for(auto i: mpp) {
            vector<int> temp;
            for(auto j: i.second) {
                for(auto k: j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};