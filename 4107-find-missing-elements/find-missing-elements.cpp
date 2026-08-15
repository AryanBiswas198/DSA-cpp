class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int start = nums[0], end = nums[n-1];
        
        vector<int> ans;
        set<int> st(nums.begin(), nums.end());

        for(int i=start; i<=end; i++) {
            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};