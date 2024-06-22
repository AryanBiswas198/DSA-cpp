class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Brute Force Approach
//         int zcnt = 0, ocnt = 0, tcnt = 0;
//         for(auto it: nums){
//             if(it == 0){
//                 zcnt++;
//             }
//             else if(it == 1){
//                 ocnt++;
//             }
//             else{
//                 tcnt++;
//             }
//         }
        
//         vector<int> ans;
//         while(zcnt--){
//             ans.push_back(0);
//         }
        
//         while(ocnt--){
//             ans.push_back(1);
//         }
        
//         while(tcnt--){
//             ans.push_back(2);
//         }
        
//         nums = ans;
        
        
        
        
        // **********Optimal Approach***********
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high--]);
            }
        }
    }
};