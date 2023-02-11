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
    int getLength(ListNode* head){
        int count = 0;
        while(head != NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) // For single element
            return head;
        
        int len = getLength(head);
        k = k%len;
        
        while(k--){
            ListNode* first = head;
            ListNode* prev = NULL;
            
            while(first != NULL){
                if(first->next == NULL){
                    prev->next = NULL;
                    ListNode* d = new ListNode(first->val);
                    d->next = head;
                    head = d;
                    
                    first = first->next;
                }
                else{
                    prev = first;
                    first = first->next;
                }
            }
        }
        return head;
    }
};