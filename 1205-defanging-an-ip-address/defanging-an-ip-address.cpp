class Solution {
public:
    string defangIPaddr(string address) {
        
        string ans = "";
        for(auto it: address) {
            it == '.' ? ans += "[.]" : ans += it;
        }
        return ans;
    }
};