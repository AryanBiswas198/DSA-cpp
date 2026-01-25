class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int n = nums.size(), mini = INT_MAX;
        sort(nums.begin(), nums.end());
        deque<int> dq;

        for(int i=0; i<n; i++) {
            if(dq.size() < k) {
                dq.push_back(nums[i]);
            }
            else {
                int low = dq.front(), high = dq.back();
                int diff = high - low;
                mini = min(mini, diff);
                dq.pop_front();
                dq.push_back(nums[i]);
            }
        }

        mini = min(mini, dq.back() - dq.front());
        return mini;
    }
};