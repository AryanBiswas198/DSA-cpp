class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++) {
            int num = nums[i], digcnt = 0;
            while(num != 0) {
                num /= 10;
                digcnt++;
            }
            if(digcnt % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};