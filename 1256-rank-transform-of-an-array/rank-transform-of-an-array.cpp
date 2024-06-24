class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = arr.size(), i = 1, prevEle;
        
        if(n == 0){
            return {};
        }
        
        for(int i=0; i<n; i++){
            pq.push({arr[i], i});
        }
        
        vector<int> ans(n, 0);
        
        prevEle = pq.top().first;
        
        while(!pq.empty()){
            
            auto top = pq.top();
            pq.pop();
            
            int ele = top.first, index = top.second;
            
            if(prevEle == ele){
                ans[index] = i;
            }
            else{
                ans[index] = ++i;
            }
            
            prevEle = ele;
        }
        return ans;
    }
};