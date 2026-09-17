class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st;

        for(auto it: banned) {
            st.insert(it);
        }

        int sum = 0, ele = 1, cnt = 0;
        while(ele <= n) {
            if(st.find(ele) == st.end() && (sum + ele <= maxSum)) {
                sum += ele;
                cnt++;
            }
            ele++;
        }
        return cnt;
    }
};