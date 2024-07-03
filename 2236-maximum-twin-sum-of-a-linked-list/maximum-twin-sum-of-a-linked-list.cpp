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
    int pairSum(ListNode* head) {
        
        int cnt = 0;
        ListNode *temp = head;
        vector<int> arr;
        
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
            cnt++;
        }
        
        int low = 0, high = cnt-1, ans = 0;
        
        while(low < high){
            int sum = arr[low++] + arr[high--];
            ans = max(ans, sum);
        }
        return ans;
    }
};