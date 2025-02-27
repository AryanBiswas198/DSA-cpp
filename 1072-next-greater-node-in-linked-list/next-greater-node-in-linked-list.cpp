/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next == NULL) {
            return {0};
        }

        vector<int> arr, ans;
        ListNode *temp = head;

        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        stack<int> st;
        int n = arr.size();

        for(int i=n-1; i>=0; i--) {
            int ele = arr[i];
            while(!st.empty() && st.top() <= ele) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top());
            }

            st.push(ele);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};