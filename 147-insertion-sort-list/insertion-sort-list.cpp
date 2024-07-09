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
    ListNode* insertionSortList(ListNode* head) {
        
        vector<int> arr;
        ListNode *temp = head;
        int n = 0;
        
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
            n++;
        }
        
        for(int i=1; i<n; i++){
            int val = arr[i], j = i-1;
            while(j >= 0 && val < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = val;
        }
        
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