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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode *temp = head;
        int len = 1;
        while(temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        temp->next = head;

        k = k%len;
        int cnt = len - k;
        while(cnt--) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};