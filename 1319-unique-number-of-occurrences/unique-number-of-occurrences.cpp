class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mpp;
        for(auto it: arr) {
            mpp[it]++;
        }

        set<int> st;
        for(auto it: mpp) {
            int val = it.first, cnt = it.second;
            if(st.find(cnt) != st.end()) {
                return false;
            }
            st.insert(cnt);
        }
        return true;
    }
};