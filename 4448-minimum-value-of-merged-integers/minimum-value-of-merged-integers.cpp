class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        
        int n = nums.size(), mini = INT_MAX;

        for(int i=0; i<=n-2; i+=2) {
            int x = nums[i], y = nums[i+1];

            string str = to_string(x) + to_string(y);
            mini = min(mini, stoi(str));
        }
        return mini;
    }
};