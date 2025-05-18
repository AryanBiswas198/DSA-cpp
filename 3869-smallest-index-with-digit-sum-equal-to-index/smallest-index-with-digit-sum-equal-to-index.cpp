class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size(), ans = 1e9;
        for(int i=0; i<n; i++) {
            int num = nums[i], sum = 0;
            while(num != 0) {
                int lastd = num%10;
                sum += lastd;
                num /= 10;
            }
            if(sum == i) {
                ans = min(ans, sum);
            }
        }
        return ans != 1e9 ? ans : -1;
    }
};