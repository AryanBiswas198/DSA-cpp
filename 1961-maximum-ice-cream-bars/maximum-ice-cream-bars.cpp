class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int n = costs.size(), cnt = 0, cost = 0;
        sort(costs.begin(), costs.end());

        for(auto it: costs) {
            if(coins - it < 0) {
                break;
            }
            coins -= it;
            cnt++;
        }
        return cnt;
    }
};