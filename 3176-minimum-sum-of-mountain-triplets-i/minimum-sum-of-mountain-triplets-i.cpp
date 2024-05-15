class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        // TC: O(N^3)
        int n = nums.size(), sum = INT_MAX;
        
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[j] > nums[i] && nums[j] > nums[k]){
                        sum = min(sum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return sum == INT_MAX ? -1 : sum;
    }
};