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
        
        if(head == NULL || k == 0){
            return head;
        }
        
        deque<int> dq;
        int len = 0, cnt = 0;
        ListNode *temp = head;
        
        while(temp != NULL){
            dq.push_back(temp->val);
            len++;
            temp = temp->next;
        }
        
        while(cnt < (k%len)){
            int val = dq.back();
            dq.pop_back();
            dq.push_front(val);
            cnt++;
        }
        
        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;
        
        while(!dq.empty()){
            int val = dq.front();
            dq.pop_front();
            ListNode *newNode = new ListNode(val);
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        return ansHead->next;
    }
};