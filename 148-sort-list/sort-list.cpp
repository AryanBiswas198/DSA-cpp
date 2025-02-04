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
        
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *sortLL(ListNode *left, ListNode *right) {
        if(left == NULL) {
            return right;
        }
        
        if(right == NULL) {
            return left;
        }

        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;

        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                ansTail->next = left;
                ansTail = ansTail->next;
                left = left->next;
            }
            else{
                ansTail->next = right;
                ansTail = ansTail->next;
                right = right->next;
            }
        }

        while(left != NULL) {
            ansTail->next = left;
            ansTail = ansTail->next;
            left = left->next;
        }

        while(right != NULL) {
            ansTail->next = right;
            ansTail = ansTail->next;
            right = right->next;
        }

        return ansHead->next;
    }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *middle = getMiddle(head);
        ListNode *left = head, *right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return sortLL(left, right);
    }
};