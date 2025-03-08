class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        string str = "";
        int n = blocks.size(), ans = INT_MAX;
        for(int i=0; i<=n-k; i++) {
            str = blocks.substr(i, k);
            int cnt = 0;
            for(int j=0; j<str.size(); j++) {
                if(str[j] == 'W') {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};