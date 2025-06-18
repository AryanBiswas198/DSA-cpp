/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) {
            return head;
        }

        Node *ansHead = NULL, *ansTail = ansHead, *temp = head;

        while(temp != NULL) {
            Node *newNode = new Node(temp->val);
            if(ansHead == NULL) {
                ansHead = newNode;
                ansTail = ansHead;
            }
            else{
                ansTail->next = newNode;
                ansTail = ansTail->next;
            }
            temp = temp->next;
        }

        unordered_map<Node*, Node*> mpp;
        temp = head;
        ansTail = ansHead;

        while(temp != NULL && ansTail != NULL) {
            mpp[temp] = ansTail;
            temp = temp->next;
            ansTail = ansTail->next;
        }

        temp = head;
        ansTail = ansHead;

        while(temp != NULL && ansTail != NULL) {
            ansTail->random = mpp[temp->random];
            temp = temp->next;
            ansTail = ansTail->next;
        }

        return ansHead;
    }
};