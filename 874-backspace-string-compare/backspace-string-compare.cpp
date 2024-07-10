class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>s1, s2;
        
        for(auto it: s){
            if(it == '#'){
                if(s1.empty()){
                    continue;
                }
                else{
                    s1.pop();
                }
            }
            else{
                s1.push(it);
            }
        }
        
        for(auto it: t){
            if(it == '#'){
                if(s2.empty()){
                    continue;
                }
                else{
                    s2.pop();
                }
            }
            else{
                s2.push(it);
            }
        }
        
        string str1, str2;
        
        while(!s1.empty()){
            auto top = s1.top();
            s1.pop();
            str1 += top;
        }
        
        while(!s2.empty()){
            auto top = s2.top();
            s2.pop();
            str2 += top;
        }
        
        return str1 == str2;
    }
};