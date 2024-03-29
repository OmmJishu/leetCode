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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        
        int start = count-n;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(count == n){
            return head->next;
        }
        
        for(int i = 0; i<start; i++){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};