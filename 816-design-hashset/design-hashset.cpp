class MyHashSet {
public:
    int mpp[1000001];
    MyHashSet() {
        for(int i=0; i<1000001; i++){
            mpp[i] = -1;
        }
    }
    
    void add(int key) {
        mpp[key] = key;
    }
    
    void remove(int key) {
        mpp[key] = -1;
    }
    
    bool contains(int key) {
        return mpp[key] != -1 ? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */