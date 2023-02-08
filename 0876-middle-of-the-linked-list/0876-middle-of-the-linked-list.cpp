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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* counter = head;
        int size = 0;
        while(counter != NULL){
            counter = counter->next;
            size++;
        }
        size = size/2;
        
        int count = 0;
        ListNode* temp = head;
        while(count < size){
            temp = temp->next;
            count++;
        }
        
        return temp;
    }
};