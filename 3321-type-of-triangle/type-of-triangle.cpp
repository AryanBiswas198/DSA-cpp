class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }

        int cnt = 0;
        if(nums[0] + nums[1] > nums[2]) {
            cnt++;
        }
        if(nums[0] + nums[2] > nums[1]) {
            cnt++;
        }
        if(nums[1] + nums[2] > nums[0]) {
            cnt++;
        }

        if(cnt >= 3) {
            if((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[0] == nums[2])) {
                return "isosceles";
            }
            else{
                return "scalene";
            }
        }
        else{
            return "none";
        }
    }
};