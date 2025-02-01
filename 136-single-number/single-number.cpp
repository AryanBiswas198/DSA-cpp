class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it: mpp) {
            if(it.second == 1) {
                return it.first;
            }
        }
        return 0;
    }
};