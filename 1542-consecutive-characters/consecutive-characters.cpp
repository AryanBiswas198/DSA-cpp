class Solution {
public:
    int maxPower(string s) {
        
        int cnt = 1, ans = 1;
        
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                ans = max(ans, ++cnt);
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};