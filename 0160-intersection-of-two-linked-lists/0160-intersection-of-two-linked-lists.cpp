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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		while(headA != NULL){
			ListNode* B = headB;
			while(B != NULL){
				if(headA == B){
					return headA;
				}
				B = B->next;
			}
			headA = headA -> next;
		}
		return NULL;
    }
};