class Solution {
public:
    bool isHappy(int n) {

        long long num = n;        
        unordered_set<int> st;

        while(st.find(num) == st.end() && num != 1) {
            st.insert(num);
            long long digits = num, newDigit = 0;
            while(digits != 0) {
                long long lastd = digits % 10;
                newDigit += (lastd*lastd);
                digits /= 10;
            }
            num = newDigit;
        }

        return num == 1 ? true : false;
    }
};