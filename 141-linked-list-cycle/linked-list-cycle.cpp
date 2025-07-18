/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head, *fast = head;

        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};