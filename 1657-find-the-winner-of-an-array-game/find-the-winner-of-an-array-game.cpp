class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int n = arr.size();
        if(k >= n) {
            return *max_element(arr.begin(), arr.end());
        }

        int winner = arr[0], cnt = 0;

        for(int i=1; i<n; i++) {
            if(winner > arr[i]) {
                cnt++;
            }
            else{
                winner = arr[i];
                cnt = 1;
            }

            if(cnt >= k) {
                return winner;
            }
        }
        return winner;
    }
};