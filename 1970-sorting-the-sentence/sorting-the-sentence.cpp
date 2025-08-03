class Solution {
public:
    string sortSentence(string s) {
        
        int n = s.size(), i = 0;
        string ans = "";
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        while(i < n) {
            if(s[i] == ' ') {
                i++;
                continue;
            }

            string temp = "";
            while(true) {
                if(s[i] - '0' >= 1 && s[i] - '0' <= 9) {
                    break;
                }
                temp += s[i++];
            }

            pq.push({s[i], temp});
            i++;
        }

        while(!pq.empty()) {
            ans += pq.top().second;
            pq.pop();
            ans += " ";
        }
        return ans.substr(0, ans.size()-1);
    }
};