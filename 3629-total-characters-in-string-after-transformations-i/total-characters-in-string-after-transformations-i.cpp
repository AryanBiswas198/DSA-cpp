class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        int freq[26];
        int mod = 1e9+7;
        for(auto it: s) {
            freq[it - 'a']++;
        }

        while(t--) {
            int newFreq[26] = {0};
            for(int ch=0; ch<26; ch++) {
                int count = freq[ch];
                if(count == 0) {
                    continue;
                }

                if(ch != 25) {
                    newFreq[ch+1] = (newFreq[ch+1] + count) % mod;
                }
                else{
                    newFreq[0] = (newFreq[0] + count) % mod;
                    newFreq[1] = (newFreq[1] + count) % mod;
                }
            }

            for(int ch=0; ch<26; ch++) {
                freq[ch] = newFreq[ch];
            }
        }

        int cnt = 0;
        for(auto it: freq) {
            cnt = (cnt + it) % mod;
        }
        return cnt;
    }
};