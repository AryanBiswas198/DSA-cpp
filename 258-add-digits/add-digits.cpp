class Solution {
public:
    int addDigits(int num) {
        
        int newNum = num;
        while(newNum >= 10){
            int sum = 0;
            while(num != 0){
                int lastd = num%10;
                sum += lastd;
                num /= 10;
            }
            newNum = sum;
            num = sum;
        }
        return newNum;
    }
};