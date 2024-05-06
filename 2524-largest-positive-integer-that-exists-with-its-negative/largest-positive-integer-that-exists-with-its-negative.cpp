class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        set<int> st;
        int n = nums.size(), maxi = 0;
        
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(st.find(num*-1) != st.end()){
                maxi = max(maxi, abs(num));
            }
            else{
                st.insert(num);
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};