class Solution {
public:
    int mirrorDistance(int n) {
        
        int num = n, rev = 0;
        while(n != 0) {
            int lastd = n % 10;
            rev = (rev*10) + lastd;
            n /= 10;
        }

        return abs(num - rev);
    }
};