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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it: lists) {
            ListNode *head = it;
            while(head != NULL) {
                int val = head->val;
                pq.push(val);
                head = head->next;
            }
        }
        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;

        while(!pq.empty()) {
            ListNode *newNode = new ListNode(pq.top());
            pq.pop();
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        ansTail->next = NULL;
        return ansHead->next;
    }
};