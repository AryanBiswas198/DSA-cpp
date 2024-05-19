class Solution {
public:
    void f(int A, int B, string &res, char a, char b){
        if(B > A){
            return f(B, A, res, b, a);
        }
        
        while(A > 0){
            res += a;
            A--;
            if(A > B){
                res += a;
                A--;
            }
            
            if(B > 0){
                res += b;
                B--;
            }
        }
    }
    
    string strWithout3a3b(int a, int b) {
        
        string res = "";
        char x = 'a', y = 'b';
        
        f(a, b, res, x, y);
        return res;
    }
};