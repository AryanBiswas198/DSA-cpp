class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        
        vector<int> res;
        map<int, int> mpp;
        
        for(auto it: bulbs) {
            mpp[it]++;
        }

        for(auto it: mpp) {
            int bulb = it.first, cnt = it.second;
            if(cnt % 2 != 0) {
                res.push_back(bulb);
            }
        }
        return res;
    }
};