class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        bool ans = true;
        if(st.find(val) != st.end()){
            ans = false;
        }
        st.insert(val);
        return ans;
    }
    
    bool remove(int val) {
        bool ans = true;
        if(st.find(val) == st.end()){
            ans = false;
        }
        st.erase(val);
        return ans;
    }
    
    int getRandom() {
        int r = rand()%st.size();
        return *next(st.begin(), r);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */