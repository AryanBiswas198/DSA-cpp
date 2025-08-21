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
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head, *prev = NULL, *forward = NULL;
        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void insertAtTail(ListNode* &ansHead, ListNode* &ansTail, int digit) {
        ListNode *newNode = new ListNode(digit);
        if(ansHead == NULL) {
            ansHead = newNode;
            ansTail = ansHead;
        }
        else{
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
    }

    ListNode *getDoubleVal(ListNode *l1, ListNode *l2) {

        ListNode *ansHead = NULL, *ansTail = NULL;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = 0;
            if(l1 != NULL) {
                val1 = l1->val;
            }

            int val2 = 0;
            if(l2 != NULL) {
                val2 = l2->val;
            }

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if(l1 != NULL) {
                l1 = l1->next;
            }

            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        return ansHead;
    }

    ListNode* doubleIt(ListNode* head) {
        
        ListNode *l1 = reverse(head);
        ListNode *doubleVal = getDoubleVal(l1, l1);

        ListNode *ans = reverse(doubleVal);
        return ans;
    }
};