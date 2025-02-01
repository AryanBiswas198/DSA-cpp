class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxi = 0, cnt = 0, n = nums.size();
        for(auto it: nums) {
            if(it == 0) {
                cnt = 0;
            }
            else{
                ++cnt;
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};