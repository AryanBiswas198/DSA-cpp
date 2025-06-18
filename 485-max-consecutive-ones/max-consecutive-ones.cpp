class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0, ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                cnt++;
            }
            else{
                ans = max(cnt, ans);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};