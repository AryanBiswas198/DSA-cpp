class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) cnt++;
            }
        }
        return cnt;
    }
};