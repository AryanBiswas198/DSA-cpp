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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            int sum = 0;
            sum += carry;

            if(l1 != NULL) {
                sum += l1->val;
            }

            if(l2 != NULL) {
                sum += l2->val;
            }

            int digit = sum % 10;
            ListNode *newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = ansTail->next;

            carry = sum / 10;
            if(l1 != NULL) {
                l1 = l1->next;
            }

            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        return ansHead->next;
    }
};