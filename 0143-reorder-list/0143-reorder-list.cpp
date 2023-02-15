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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL || head->next->next == NULL) 
            return;
        
        ListNode* tempHead = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        
        curr->next = tempHead->next;
        tempHead->next = curr;
        tempHead = curr;
        prev->next = NULL;
        
        reorderList(tempHead->next);
    }
};