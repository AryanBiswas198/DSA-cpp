class RandomizedCollection {
public:
    unordered_multiset<int> mst;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans = false;
        if(mst.find(val) == mst.end()){
            ans = true;
        }
        mst.insert(val);
        return ans;
    }
    
    bool remove(int val) {
        bool ans = false;
        if(mst.find(val) != mst.end()){
            mst.erase(mst.find(val));
            ans = true;
        }
        return ans;
    }
    
    int getRandom() {
        int r = rand()%mst.size();
        return *next(mst.begin(), r);
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */