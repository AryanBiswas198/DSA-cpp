class Solution {
public:
    bool isPrime(int num) {
        if(num <= 1) {
            return false;
        }

        for(int i=2; i<=sqrt(num); i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        
        vector<int> primes;
        for(int i=left; i<=right; i++) {
            if(isPrime(i)) {
                primes.push_back(i);
            }
        }

        if(primes.size() < 2) {
            return {-1, -1};
        }

        int minDiff = INT_MAX;
        vector<int> ans;
        for(int i=1; i<primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                ans = {primes[i-1], primes[i]};
            }
        }
        return ans;
    }
};