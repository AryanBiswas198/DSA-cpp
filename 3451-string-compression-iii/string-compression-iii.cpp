class Solution {
public:
    string compressedString(string word) {
        
        int n = word.size(), cnt = 1;
        string res = "";
        
        for(int i=0; i<n; i++){
            if(word[i] != word[i+1] || cnt == 9 || i == n-1){
                string val = to_string(cnt);
                res += val+word[i];
                cnt = 1;
                continue;
            }
            cnt++;
        }
        return res;
    }
};