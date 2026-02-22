class Solution {
public:
    int binaryGap(int n) {
        
        int num = n;
        string binary = "";
        
        while(num != 0) {
            num % 2 == 0 ? binary.append("0") : binary.append("1");
            num /= 2;
        }

        reverse(binary.begin(), binary.end()); 

        int i = 0, maxCnt = 0, sz = binary.size();
        while(i < sz) {
            if(binary[i] == '0') {
                i++;
                continue;
            }

            int j = i+1;
            while(j < sz && binary[j] != '1') {
                j++;
            }
            
            if(j < sz) {
                maxCnt = max(maxCnt, j-i);
            }
            i = j;
        }
        return maxCnt;
    }
};