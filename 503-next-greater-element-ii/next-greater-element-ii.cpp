class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i=2*n-1; i>=0; i--) {
            int ele = nums[i%n];
            while(!st.empty() && st.top() <= ele) {
                st.pop();
            }

            if(st.empty()) {
                ans[i%n] = -1;
            }
            else{
                ans[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};