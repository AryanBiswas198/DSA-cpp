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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        
        ListNode *ansHead = new ListNode(-1);
        ListNode *tail = ansHead;
        
        while(head != NULL){
            if(st.find(head->val) == st.end()){
                ListNode *node = new ListNode(head->val);
                tail->next = node;
                tail = tail->next;
            }
            head = head->next;
        }
        return ansHead->next;
    }
};