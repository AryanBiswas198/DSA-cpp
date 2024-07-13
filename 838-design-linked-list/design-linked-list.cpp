class Node {
    public:
        int val;
        Node *next;
        Node (int val){
            this->val = val;
            next = NULL;
        }
};


class MyLinkedList {
public:
    int sz;
    Node *head;
    MyLinkedList() {
        head = new Node(0);
        sz = 0;
    }
    
    int get(int index) {
        
        if(index >= sz) return -1;
        
        Node *temp = head->next;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
       Node *forward = head->next;
        Node *newNode = new Node(val);
        head->next = newNode;
        newNode->next = forward;
        sz++;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        
        if(index > sz) return ;
        
        Node *newNode = new Node(val);
        Node *temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        
        Node *forward = temp->next;
        temp->next = newNode;
        newNode->next = forward;
        sz++;
    }
    
    void deleteAtIndex(int index) {
        
        if(index >= sz) return ;
        
        Node *temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */