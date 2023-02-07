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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        
        while(head->val == val){
            head = head->next;
            if(head == NULL)
                return NULL;
        }
        
       ListNode* first = head;
        
        while(first->next != NULL){
            ListNode* temp = first;
            first = first->next;
            
            if(first->val == val){
                temp->next = first->next;
                first = temp;
            }
        }
        if(first->val == val)
            return NULL;
        
        return head;
    }
};