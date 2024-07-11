class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int, int> mpp;
        for(auto it: nums){
            if(mpp[it] < 2){
                mpp[it]++;
            }
        }
        
        int i = 0, ans = 0;
        while(!mpp.empty()){
            auto top = mpp.begin();
            int ele = top->first;
            int cnt = top->second;
            
            mpp.erase(top);
            
            while(cnt--){
                nums[i++] = ele;
                ans++;
            }
        }
        
        // for(int i=0; i<nums.size(); i++){
        //     cout<<nums[i]<<" ";
        // }
        
        return ans;
    }
};