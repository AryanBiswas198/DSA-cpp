class Solution {
public:
    int minimumChairs(string s) {
        
        int maxi = 0, cnt = 0;
        for(auto it: s){
            it == 'E' ? cnt += 1 : cnt -= 1;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};