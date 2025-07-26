class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size(), cnt = 0;
        long long prod = 1;

        for(int i=0; i<n; i++) {
            prod = nums[i];
            if(prod < k) {
                cnt++;
            }
            for(int j=i+1; j<n; j++) {
                prod *= nums[j];
                if(prod < k) {
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};