class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        
        int i = 0, ans = st.size();
        while(!st.empty()){
            auto topEle = *(st.begin());
            st.erase(topEle);
            nums[i++] = topEle;
        }
        return ans;
    }
};