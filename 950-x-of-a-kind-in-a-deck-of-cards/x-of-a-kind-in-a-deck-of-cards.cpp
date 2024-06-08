class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        map<int, int> mpp;
        
        for(auto it: deck){
            mpp[it]++;
        }
        
        int val = mpp.begin()->second;
        
        for(auto it: mpp){
            val = __gcd(val, it.second);
        }
        
        return val != 1;
    }
};