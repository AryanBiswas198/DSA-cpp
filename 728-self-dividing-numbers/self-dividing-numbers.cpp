class Solution {
public:
    bool isValid(int num) {
        int n = num;
        while(n != 0) {
            int lastd = n % 10;
            if(lastd == 0 || num % lastd != 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int num=left; num<=right; num++) {
            if(isValid(num)) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};