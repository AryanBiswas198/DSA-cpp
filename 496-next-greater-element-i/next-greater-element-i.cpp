class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mpp;

        int n1 = nums1.size(), n2 = nums2.size();

        for(int i=n2-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                mpp[nums2[i]] = -1;
            }
            else{
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        
        vector<int> ans(n1, 0);
        for(int i=0; i<n1; i++) {
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};