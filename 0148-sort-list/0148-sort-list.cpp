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
    ListNode* findMid(ListNode* head){ // Function for finding mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* lefthalf, ListNode* righthalf){ // Merge function
        if(lefthalf == NULL) return righthalf;
        if(righthalf == NULL) return lefthalf;
        
        ListNode* store = new ListNode();
        ListNode* temp = store;
        
        while(lefthalf != NULL && righthalf != NULL){
            if(lefthalf->val < righthalf->val){
                temp->next = lefthalf;
                lefthalf = lefthalf->next;
            }
            else{
                temp->next = righthalf;
                righthalf = righthalf->next;
            }
            temp = temp->next;
        }
        
        while(lefthalf != NULL){
            temp->next = lefthalf;
            lefthalf = lefthalf->next;
            temp = temp->next;
        }
        while(righthalf != NULL){
            temp->next = righthalf;
            righthalf = righthalf->next;
            temp = temp->next;
        }
        return store->next;
    }
    
    ListNode* sortList(ListNode* head) { // Main Function
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* mid = findMid(head);
        
        ListNode* lefthalf = head;
        ListNode* righthalf = mid->next;
        mid->next = NULL;
        
        lefthalf = sortList(lefthalf);
        righthalf = sortList(righthalf);
        
        ListNode* res = merge(lefthalf, righthalf);
        
        return res;
    }
};