class MyHashMap {
public:
    int mpp[1000001];
    MyHashMap() {
        for(int i=0; i<1000001; i++){
            mpp[i] = -1;
        }
    }
    
    void put(int key, int value) {
        mpp[key] = value;
    }
    
    int get(int key) {
        return mpp[key];
    }
    
    void remove(int key) {
        mpp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */