class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        
        int num = n, i = 0;
        vector<int> ans;

        while(num != 0) {
            int lastd = num % 10;
            if(lastd != 0) {
                long long res = pow(10, i) * lastd;
                ans.push_back(res);   
            }
            num /= 10;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};