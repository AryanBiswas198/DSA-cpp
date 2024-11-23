class Solution {
public:
    bool canAliceWin(int n) {
        int ans = 0, i = 10;
        while(ans <= n){
            if(ans == n) return i%2==0 ? false: true;
            ans += i;
            if(ans > n) {
                break;
            }
            --i;
        }
        return i % 2 == 0 ? false : true;
    }
    // 10 19 27 34 40 45 49
};