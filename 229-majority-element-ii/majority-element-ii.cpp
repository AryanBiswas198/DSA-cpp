class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size(), target = n/3;
        vector<int> ans;
        set<int> st;
        unordered_map<int, int> mpp;
        
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it] > target){
                st.insert(it);
            }
        }
        
        while(!st.empty()){
            auto top = *(st.begin());
            ans.push_back(top);
            st.erase(top);
        }
        return ans;
    }
};