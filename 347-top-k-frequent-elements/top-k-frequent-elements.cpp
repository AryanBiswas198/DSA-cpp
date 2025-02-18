#include<bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        map<int, int> mpp;
        priority_queue<pair<int, int>> pq;

        for(auto it: nums) {
            if(mpp.find(it) != mpp.end()) {
                mpp[it]++;
            }
            else{
                mpp.insert({it, 1});
            }
        }

        for(auto it: mpp) {
            int val = it.first, cnt = it.second;
            pq.push({cnt, val});
        }
        
        while(!pq.empty() && k--) {
            int val = pq.top().second;
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
};