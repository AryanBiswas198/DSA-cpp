class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        set<int> st;
        vector<string> ans;
        int sz = target.size(), limit = target[sz-1];

        for(auto it: target) {
            st.insert(it);
        }

        for(int i=1; i<=limit; i++) {
            ans.push_back("Push");
            if(st.find(i) == st.end()) {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};