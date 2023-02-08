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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) // for 1 element
            return NULL;
        
        ListNode* counter = head;
        int size = 0;
        while(counter != NULL){
            counter = counter->next;
            size++;
        }
        size = size/2;
        
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            prev = curr;
            curr = curr->next;
            count++;
            if(count == size){
                prev->next = curr->next;
                break;
            }
        }
        return head;
    }
};