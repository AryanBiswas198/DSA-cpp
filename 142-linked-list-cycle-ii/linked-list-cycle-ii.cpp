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

        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                ListNode *intersection = slow, *temp = head;
                while(intersection != temp) {
                    temp = temp->next;
                    intersection = intersection->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};