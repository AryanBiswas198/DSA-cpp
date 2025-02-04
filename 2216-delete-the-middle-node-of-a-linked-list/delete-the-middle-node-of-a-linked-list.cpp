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
    ListNode *getMiddle(ListNode *head) {
        ListNode *slow = head, *fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL) {
            return NULL;
        }

        ListNode *middle = getMiddle(head);
        middle->next = middle->next->next;
        return head;
    }
};