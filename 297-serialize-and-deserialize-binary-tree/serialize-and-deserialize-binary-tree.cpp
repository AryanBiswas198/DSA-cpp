/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }

        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            if(front == NULL) {
                str.append("#,");
            }
            else{
                str.append(to_string(front->val)+',');
            }

            if(front != NULL) {
                q.push(front->left);
                q.push(front->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) {
            return NULL;
        }

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                front->left = NULL;
            }
            else{
                TreeNode *leftNode = new TreeNode(stoi(str));
                front->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#") {
                front->right = NULL;
            }
            else{
                TreeNode *rightNode = new TreeNode(stoi(str));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));