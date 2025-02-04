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
        
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        if(head->next->next == NULL) {
            head->next = NULL;
            return head;
        }

        ListNode *beforeMiddleNode = getMiddle(head);
        beforeMiddleNode->next = beforeMiddleNode->next->next;
        return head;
    }
};