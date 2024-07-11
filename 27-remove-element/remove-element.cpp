class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        queue<int> q;
        for(auto it: nums){
            if(it != val) q.push(it);
        }
        
        int i = 0, ans = q.size();
        while(!q.empty()){
            auto topEle = q.front();
            q.pop();
            nums[i++] = topEle;
        }
        return ans;
    }
};