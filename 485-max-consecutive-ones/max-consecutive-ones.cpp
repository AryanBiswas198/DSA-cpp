class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0, ans = 0;
        for(auto it: nums){
            if(it == 1){
                ans = max(ans, ++cnt);
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
};