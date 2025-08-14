class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n = num.size(), cnt = 1, maxNum = -1, limit = 3;
        for(int i=1; i<n; i++) {
            if(num[i] == num[i-1]) {
                ++cnt;
                if(cnt == 3) {
                    int no = num[i] - '0';
                    maxNum = max(maxNum, no);
                }
            }
            else{
                cnt = 1;
            }
        }
        if(maxNum == -1) {
            return "";
        }
        string ans = "";
        while(limit--) {
            ans.push_back(maxNum + '0');
        }
        return ans;
    }
};