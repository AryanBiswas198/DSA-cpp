class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        int n = num1.size(), m = num2.size();
        string ans(n+m, '0');
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int res = (ans[i+j+1]-'0') + ((num1[i] - '0')*(num2[j] - '0'));
                ans[i+j+1] = res%10 + '0';
                ans[i+j] += res/10;
            }
        }
        
        if(ans[0] == '0'){
            return ans.substr(1);
        }
        
        return ans;
    }
};