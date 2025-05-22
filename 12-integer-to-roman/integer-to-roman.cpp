class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        while(num) {
            if(num >= 1000) {
                ans += string(num/1000, 'M');
                num %= 1000;
            }
            else if(num >= 900) {
                ans += "CM";
                num -= 900;
            }
            else if(num >= 500) {
                ans += string(num / 500, 'D');
                num -= 500;
            }
            else if(num >= 400) {
                ans += "CD";
                num -= 400;
            }
            else if(num >= 100) {
                ans += string(num/100, 'C');
                num %= 100;
            }
            else if(num >= 90) {
                ans += "XC";
                num -= 90;
            }
            else if(num >= 50) {
                ans += string(num / 50, 'L');
                num -= 50;
            }
            else if(num >= 40) {
                ans += "XL";
                num -= 40;
            }
            else if(num >= 10) {
                ans += string(num / 10, 'X');
                num %= 10;
            }
            else if(num == 9) {
                ans += "IX";
                num -= 9;
            }
            else if(num >= 5) {
                ans += "V";
                num -= 5;
            }
            else if(num == 4) {
                ans += "IV";
                num -= 4;
            }
            else if(num >= 1) {
                ans += string(num / 1, 'I');
                num %= 1;
            }
        }
        return ans;
    }
};