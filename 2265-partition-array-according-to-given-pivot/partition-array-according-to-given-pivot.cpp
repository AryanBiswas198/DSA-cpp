class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size(), pivotCnt = 0;
        if(n == 1) {
            return {nums[0]};
        }

        vector<int> temp1, temp2;
        for(auto it: nums) {
            if(it == pivot) {
                pivotCnt++;
            }
            else if(it < pivot) {
                temp1.push_back(it);
            }
            else{
                temp2.push_back(it);
            }
        }

        while(pivotCnt--) {
            temp1.push_back(pivot);
        }

        for(auto it: temp2 ) {
            temp1.push_back(it);
        }
        return temp1;
    }
};