class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        int cnt = k;
        while(q.size() != 1) {
            while(--cnt) {
                q.push(q.front());
                q.pop();
            }
            if(cnt == 0) {
                q.pop();
                cnt = k;
            }
        }
        return q.front();
    }
};