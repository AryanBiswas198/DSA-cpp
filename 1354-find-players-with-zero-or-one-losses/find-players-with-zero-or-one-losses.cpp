class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int> mpp;
        int n = matches.size();
        
        for(auto it: matches){
            if(mpp.find(it[0]) == mpp.end()){
                mpp[it[0]] = 0;
            }
            mpp[it[1]]++;
        }
        
        vector<vector<int>> ans;
        vector<int> first, second;
        
        for(auto it: mpp){
            if(it.second == 0){
                first.push_back(it.first);
            }
            
            if(it.second == 1){
                second.push_back(it.first);
            }
        }
        
        ans.push_back(first);
        ans.push_back(second);
        
        return ans;
    }
};