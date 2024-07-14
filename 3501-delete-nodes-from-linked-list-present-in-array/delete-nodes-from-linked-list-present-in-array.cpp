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
        ListNode *tail = ansHead, *temp = head;
        
        while(temp != NULL){
            if(st.find(temp->val) == st.end()){
                ListNode *node = new ListNode(temp->val);
                tail->next = node;
                tail = tail->next;
            }
            temp = temp->next;
        }
        return ansHead->next;
    }
};