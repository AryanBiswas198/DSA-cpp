class Solution {
public:
    bool isPalindrome(int x) {
        int originalN = x;
        long int rev = 0;
        while(x != 0){
            int lastd = x%10;
            rev = (rev*10) + lastd;
            x/=10;
        }
        return rev == originalN && originalN >= 0;
    }
};