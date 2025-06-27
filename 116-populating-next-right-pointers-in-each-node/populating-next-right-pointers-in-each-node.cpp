/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) {
            return root;
        }

        Node *temp = root;
        queue<Node*> q;
        q.push(temp);

        while(!q.empty()) {
            int sz = q.size();
            vector<Node*> vec;
            while(sz--) {
                Node *node = q.front();
                q.pop();

                vec.push_back(node);

                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }

            int n = vec.size();
            for(int i=0; i<n-1; i++) {
                vec[i]->next = vec[i+1];
            }
            vec[n-1]->next = NULL;
        }
        return root;
    }
};