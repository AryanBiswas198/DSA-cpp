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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *slow = head, *fast = head, *intersection = head;
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }

            if(slow == fast) {
                while(slow != intersection) {
                    slow = slow->next;
                    intersection = intersection->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};