class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int, int> mpp;
        int maxi = INT_MIN;
        for(auto it: arr){
            mpp[it]++;
        }
        
        for(auto it: arr){
            if(mpp.find(it) != mpp.end()){
                if(it == mpp[it]){
                    maxi = max(maxi, it);
                }
                mpp.erase(it);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};