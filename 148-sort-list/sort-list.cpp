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
    ListNode* sortList(ListNode* head) {
        
        // Basic Approach
        
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;
        
        for(auto it: arr){
            ListNode *newNode = new ListNode(it);
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        return ansHead->next;
    }
};