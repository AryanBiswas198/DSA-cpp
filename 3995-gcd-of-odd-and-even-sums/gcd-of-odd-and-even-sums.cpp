class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int oddSum = 0, evenSum = 0;
        for(int i=1; i<=n*2; i++) {
            i % 2 != 0 ? oddSum += i : evenSum += i;
        }

        return gcd(oddSum, evenSum);
    }
};