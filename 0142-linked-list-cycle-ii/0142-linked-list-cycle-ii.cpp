/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* meet = hasCycle(head);
        if(meet == NULL)
            return NULL;
        ListNode* start = head;
        
        while(start != meet){
            start = start->next;
            meet = meet->next;
        }
        return start;
    }
};