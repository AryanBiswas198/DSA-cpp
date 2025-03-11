class Solution {
public:
    int numberOfSubstrings(string s) {
        
        vector<int> mpp(3, 0);
        int n = s.size(), count = 0, start = 0;

        for(int end=0; end<n; end++) {
            mpp[s[end] - 'a']++;

            while(mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0) {
                count += (n - end);
                mpp[s[start] - 'a']--;
                start++;
            }
        }
        return count;
    }
};