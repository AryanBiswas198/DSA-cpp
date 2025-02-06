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
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, vector<int>>> mpp;

        vector<vector<int>> ans;

        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto front = q.front();
                q.pop();

                TreeNode *val = front.first;
                int hd = front.second.first, level = front.second.second;

                mpp[hd][level].push_back(val->val);

                if(val->left != NULL) {
                    q.push({val->left, {hd-1, level+1}});
                }

                if(val->right != NULL) {
                    q.push({val->right, {hd+1, level+1}});
                }
                sort(mpp[hd][level].begin(), mpp[hd][level].end());
            }
        }

        for(auto i: mpp) {
            vector<int> temp;
            for(auto j: i.second){
                for(auto k: j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};