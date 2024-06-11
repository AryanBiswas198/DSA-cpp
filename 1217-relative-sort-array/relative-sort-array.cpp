class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int, int> mpp;
        int n = arr1.size(), i = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it: arr1){
            mpp[it]++;
            if(find(arr2.begin(), arr2.end(), it) == arr2.end()){
                pq.push(it);
            }
        }
        
        vector<int> ans;
        
        for(auto it: arr2){
            while(mpp[it] != 0){
                ans.push_back(it);
                mpp[it]--;
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};