class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int diff = INT_MAX, n = arr.size();
        
        stack<pair<int, int>> st;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for(int i=n-1; i>0; i--) {
            int absDiff = abs(arr[i] - arr[i-1]);
            if(absDiff < diff) {
                while(!st.empty()) {
                    st.pop();
                }
                diff = absDiff;
                st.push({arr[i-1], arr[i]});
            }
            else if(absDiff == diff) {
                st.push({arr[i-1], arr[i]});
            }
        }
        
        while(!st.empty()) {
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        return ans;
    }
};