class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size(), i = 0, j = 0, cnt = 0;

        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};