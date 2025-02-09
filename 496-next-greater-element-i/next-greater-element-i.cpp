class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        map<int, int> mpp;
        int n = nums2.size();

        for(int i=n-1; i>=0; i--) {
            int ele = nums2[i];
            while(!st.empty() && ele > st.top()) {
                st.pop();
            }

            if(st.empty()) {
                mpp[ele] = -1;
            }
            else{
                mpp[ele] = st.top();
            }
            st.push(ele);
        }
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};