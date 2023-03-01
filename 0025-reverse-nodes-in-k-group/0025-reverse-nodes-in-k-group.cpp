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
    ListNode* reverse(ListNode* begin, ListNode* end){
	    ListNode* prev = begin;
        ListNode* curr = begin->next;
        
        ListNode* first = curr;
        ListNode* next = NULL;

	    while (curr != end){
		    next = curr->next;
		    curr->next = prev;
		    prev = curr;
		    curr = next;
	    }
	    begin->next = prev;
	    first->next = curr;
	    return first;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k==1)
    	    return head;

        ListNode* temp = head;
        ListNode* store = new ListNode();
        store->next = temp;
        ListNode* st = store;
        int count = 0;
        
        while(temp != NULL){
            count++;
            if(count == k){
                st = reverse(st,temp->next);
                temp = st->next;
                count = 0;
            }
            else{
                temp = temp->next;
            }
        }
        return store->next;
    }
};