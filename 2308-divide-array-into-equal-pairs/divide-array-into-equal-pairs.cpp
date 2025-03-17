class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        stack<int> st;
        sort(nums.begin(), nums.end());
        for(auto it: nums) {
            st.push(it);
        }

        while(!st.empty()) {
            int val1 = st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            if(val1 != val2) {
                return false;
            }
        }
        return true;
    }
};