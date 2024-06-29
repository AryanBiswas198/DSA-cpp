class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int low = 0, high = numbers.size()-1;
        
        while(low < high){
            int val = numbers[low] + numbers[high];
            if(target == val){
                return {low+1, high+1};
            }
            else if(val < target){
                low++;
            }
            else{
                high--;
            }
        }
        return {};
    }
};