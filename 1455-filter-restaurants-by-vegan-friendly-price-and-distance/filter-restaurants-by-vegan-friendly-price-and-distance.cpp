class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        int n = restaurants.size();
        priority_queue<pair<int, int>> pq;

        for(auto it: restaurants) {
            if(it[3] <= maxPrice && it[4] <= maxDistance) {
                if(veganFriendly == 1) {
                    if(it[2] == 1) {
                        pq.push({it[1], it[0]});
                    }
                }
                else if(veganFriendly == 0) {
                    pq.push({it[1], it[0]});
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
        }
        return ans;
    }
};