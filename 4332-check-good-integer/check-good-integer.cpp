class Solution {
public:
    bool checkGoodInteger(int n) {
        
        int num = n, digitSum = 0, sqDigitSum = 0;

        while(num != 0) {
            int lastd = num % 10;
            digitSum += lastd;
            sqDigitSum += (lastd*lastd);

            num /= 10;
        }

        return sqDigitSum - digitSum >= 50;
    }
};