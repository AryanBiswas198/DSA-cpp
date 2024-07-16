class Solution {
public:
    bool isGood(vector<int>& nums) {
        
//         // First Approach - Wrong 
//         int n = nums.size(), numOfEle = n-1;
//         int sumOfNEle = numOfEle*(numOfEle+1)/2;
//         int actualSum = sumOfNEle + numOfEle;
//         int sum = 0;
        
//         for(auto it: nums){
//             sum += it;
//         }
        
//         return sum == actualSum;
        
        
        // Second Approach 
        map<int, int> mpp;
        int n = nums.size(), numOfEle = n-1;
        
        for(auto it: nums){
            ++mpp[it];
            if(it > numOfEle || (it == numOfEle && mpp[it] > 2) || (it != numOfEle && it < numOfEle && mpp[it] > 1)){
                return false;
            }
        }
        return true;
    }
};