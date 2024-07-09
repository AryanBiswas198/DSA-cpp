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
    ListNode *getMid(ListNode *head){
        
        ListNode *slow = head, *fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *sort(ListNode *left, ListNode *right){
        
        if(left == NULL){
            return right;
        }
        
        if(right == NULL){
            return left;
        }
        
        ListNode *ansHead = new ListNode(-1);
        ListNode *ansTail = ansHead;
        
        while(left != NULL && right != NULL){
            if(left->val < right->val){
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
        
        while(left != NULL){
            ansTail->next = left;
            ansTail = ansTail->next;
            left = left->next;
        }
        
        while(right != NULL){
            ansTail->next = right;
            ansTail = ansTail->next;
            right = right->next;
        }
        return ansHead->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        // Optimal Approach
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *mid = getMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode *res = sort(left, right);
        return res;
    }
};