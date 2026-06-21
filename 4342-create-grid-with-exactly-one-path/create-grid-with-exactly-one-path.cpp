class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string> res;
        for(int i=0; i<m; i++) {
            string str = "";
            for(int j=0; j<n; j++) {
                (i == 0 || j == n-1) ? str.push_back('.') : str.push_back('#');
            }
            res.push_back(str);
        }
        return res;
    }
};