class Solution {
public:
    bool checkDivisibility(int n) {
        
        int num = n, sum = 0, prod = 1;
        while(num != 0) {
            int lastd = num % 10;
            sum += lastd;
            prod *= lastd;
            num /= 10;
        }
        return n % (sum+prod) == 0;
    }
};