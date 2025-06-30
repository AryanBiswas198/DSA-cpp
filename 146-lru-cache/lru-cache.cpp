class LRUCache {

    class Node {
        public: 
            int key;
            int val;
            Node *prev;
            Node *next;

            Node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;

    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *currentNode) {
        Node *prevNode = currentNode->prev;
        Node *nextNode = currentNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node *currentNode) {
        Node *temp = head->next;
        head->next = currentNode;
        temp->prev = currentNode;
        currentNode->next = temp;
        currentNode->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node *currentNode = mpp[key];
            int res = currentNode->val;
            mpp.erase(key);
            deleteNode(currentNode);
            addNode(currentNode);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node *currentNode = mpp[key];
            mpp.erase(key);
            deleteNode(currentNode);
        }

        if(mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */