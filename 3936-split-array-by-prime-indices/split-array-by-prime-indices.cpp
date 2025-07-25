class Solution {
public:
    bool isPrime(int num) {
        if(num <= 1) {
            return false;
        }
        for(int i=2; i*i<=num; i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        
        long long n = nums.size(), sumA = 0, sumB = 0;
        for(int i=0; i<n; i++) {
            if(isPrime(i)) {
                sumA += nums[i];
            }
            else{
                sumB += nums[i];
            }
        }
        return abs(sumA - sumB);
    }
};