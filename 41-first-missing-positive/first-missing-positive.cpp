class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size(), mini = 1;
        sort(nums.begin(), nums.end());
        set<int> st;

        for(int i=0; i<n; i++) {
            if(nums[i] < 1 || st.find(nums[i]) != st.end()) continue;

            if(mini < nums[i]) {
                return mini;
            }
            st.insert(nums[i]);
            mini += 1;
        }
        return mini;
    }
};