class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for(auto it: restaurants) {
            if(it[3] <= maxPrice && it[4] <= maxDistance) {
                if((veganFriendly == 1 && it[2] == 1) || (veganFriendly == 0)) {
                    pq.push({it[1], it[0]});
                }
            }
        }

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
        }
        return ans;
    }
};