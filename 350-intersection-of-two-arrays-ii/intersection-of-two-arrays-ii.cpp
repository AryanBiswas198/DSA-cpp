class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mpp;
        vector<int> ans;
        
        for(auto it: nums1){
            mpp[it]++;
        }
        
        for(auto it: nums2){
            if(mpp.find(it) != mpp.end()){
                ans.push_back(it);
                --mpp[it];
                if(mpp[it] == 0){
                    mpp.erase(it);
                }
            }
        }
        return ans;
    }
};