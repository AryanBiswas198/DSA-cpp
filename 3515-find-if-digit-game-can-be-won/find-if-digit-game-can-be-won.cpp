class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int singleSum = 0, doubleSum = 0;
        for(auto it: nums) {
            if(it < 10) {
                singleSum += it;
            }
            else{
                doubleSum += it;
            }
        }

        return singleSum != doubleSum;
    }
};