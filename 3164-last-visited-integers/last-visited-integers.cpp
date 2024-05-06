class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        
        vector<int> seen, ans;
        int n = nums.size(), k = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                seen.push_back(nums[i]);
                k = 0;
            }
            else{
                k++;
                if(k <= seen.size()){
                    // The below line means the index of the seen vector from the last, as seen vector acts like a deque where we append elements at the front
                    ans.push_back(seen[seen.size()-k]);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};