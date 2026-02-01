class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // First element of array will always be included in the sum, the rest two will be the minimum value of the array
        int sum = nums[0], n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=1; i<n; i++) pq.push(nums[i]);

        int k = 2;
        while(k--) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};