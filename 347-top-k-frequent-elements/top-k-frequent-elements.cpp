class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int, int> mpp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                mpp[nums[i]] += 1;
            }
            else{
                mpp[nums[i]] = 1;
            }
        }

        for(auto it: mpp) {
            pq.push({it.second, it.first});
        }

        while(!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};  