class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        int i = 0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        set<int> st;
        
        while(i < j){
            int a = nums[i++], b = nums[j--];
            int sum = a+b;
            st.insert(sum);
        }
        return st.size();
    }
};