class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        
        unordered_map<int, int> mpp;
        vector<int> temp = score;
        
        sort(temp.begin(), temp.end(), greater<int>());
        
        for(int i=0; i<n; i++){
            mpp[temp[i]] = i+1;
        }
        
        vector<string> ans(n);
        
        for(int i=0; i<n; i++){
            if(mpp[score[i]] > 3){\
                ans[i] = to_string(mpp[score[i]]);
            }
            else if(mpp[score[i]] == 1){
                ans[i] = "Gold Medal";
            }
            else if(mpp[score[i]] == 2){
                ans[i] = "Silver Medal";
            }
            else{
                ans[i] = "Bronze Medal";
            }
        }
        return ans;
    }
};