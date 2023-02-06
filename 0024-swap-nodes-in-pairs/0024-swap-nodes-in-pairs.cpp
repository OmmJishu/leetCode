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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        if(temp == NULL)
            return head;
        
        int count = 0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        
        ListNode* first = head;
        ListNode* second = first->next;
        
        for(int i = 0; i<count; i=i+2){
            swap(first->val,second->val);
            if(first->next == NULL || second->next == NULL)
                return head;
            
            first = second->next;
            second = second->next->next;
        }
        return head;
    }
};