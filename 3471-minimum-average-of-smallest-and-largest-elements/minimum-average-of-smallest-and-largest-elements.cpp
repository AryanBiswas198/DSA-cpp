class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        int n = nums.size()-1, i = 0;
        double mini = 52;
        sort(nums.begin(), nums.end());
        
        while(i < n){
            double avg = double(nums[i++] + nums[n--])/2;
            mini = min(mini, avg);
        }
        return mini;
    }
};