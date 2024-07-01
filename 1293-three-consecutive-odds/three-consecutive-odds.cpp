class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size(), cnt = 0, ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] % 2 != 0){
                ++cnt;
                ans = max(ans, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return ans >= 3 ? true : false;
    }
};