class Solution {
public:
    int secondHighest(string s) {
        
        set<int> st;
        priority_queue<int> pq;

        for(auto it: s) {
            if(it - '0' >= 0 && it - '0' <= 9 && st.find(it) == st.end()) {
                pq.push(it - '0');
                st.insert(it);
            }
        }

        if(pq.empty()) return -1;

        pq.pop();
        return pq.empty() ? -1 : pq.top();
    }
};