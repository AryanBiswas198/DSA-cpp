class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        for(auto it: nums){
            if(mpp[it] > 0){
                return it;
            }
            mpp[it]++;
        }
        return 0;
    }
};