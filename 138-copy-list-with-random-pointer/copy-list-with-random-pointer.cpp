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
        
        if(head == NULL){
            return head;
        }
        
        Node *cloneHead = NULL, *cloneNode = NULL, *temp = head;
        
        while(temp != NULL){
            Node *newNode = new Node(temp->val);
            if(cloneHead == NULL){
                cloneHead = newNode;
                cloneNode = cloneHead;
            }
            else{
                cloneNode->next = newNode;
                cloneNode = cloneNode->next;
            }
            temp = temp->next;
        }
        
        unordered_map<Node*, Node*> originalToCloneNode;
        
        temp = head, cloneNode = cloneHead;
        
        while(temp != NULL && cloneNode != NULL){
            originalToCloneNode[temp] = cloneNode;
            temp = temp->next;
            cloneNode = cloneNode->next;
        }
        
        temp = head, cloneNode = cloneHead;
        
        while(cloneNode != NULL){
            cloneNode->random = originalToCloneNode[temp->random];
            cloneNode = cloneNode->next;
            temp = temp->next;
        }
        return cloneHead;
    }
};