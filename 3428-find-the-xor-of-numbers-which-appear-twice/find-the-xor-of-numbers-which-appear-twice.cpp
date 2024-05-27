class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        int val = 0;
        
        for(auto it: nums){
            mpp[it]++;
        }
        
        for(auto it: mpp){
            if(it.second == 2){
                val = val ^ it.first;
            }
        }
        return val;
    }
};