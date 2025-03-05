class Solution {
public:
    long long coloredCells(int n) {
        
        long long n1 = n, a = n-1;
        long long ans = (n1*n1) + (a*a);
        return ans;
    }
};