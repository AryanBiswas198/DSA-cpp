class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        vector<int> indexes;
        int n = nums.size(), cnt = 0, q = queries.size();
        vector<int> ans(q, -1);
        
        for(int i=0; i<n; i++){
            if(nums[i] == x){
                cnt++;
                indexes.push_back(i);
            }
        }
        
        if(cnt == 0){
            return ans;
        }
        
        for(int i=0; i<q; i++){
            if(queries[i] > cnt){
                continue;
            }
            ans[i] = indexes[queries[i]-1];
        }
        return ans;
    }
};