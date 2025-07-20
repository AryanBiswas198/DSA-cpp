class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for(auto fol: folder) {
            if(ans.empty() || fol.find(ans.back() + '/') != 0) {
                ans.push_back(fol);
            }
        }
        return ans;
    }
};