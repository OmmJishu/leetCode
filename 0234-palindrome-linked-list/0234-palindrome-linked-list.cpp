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
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast != NULL) 
                fast=fast->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* newHead = NULL;
        
        while(head != NULL){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp =head;
        ListNode* mid = findMid(temp);
        ListNode* revrs = reverse(mid);
        
        while(head != NULL && revrs != NULL){
            if(head->val != revrs->val) 
                return false;
            head = head->next;
            revrs = revrs->next;
        }
        return true;
    }
};
