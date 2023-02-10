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
    ListNode* reverse(ListNode* head){
        ListNode* prevNode = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = prevNode;
            prevNode = head;
            head = next;
        }
        return prevNode;
    }
    
    ListNode* addTwoNumbers(ListNode* List1, ListNode* List2) {
        List1 = reverse(List1);
        List2 = reverse(List2);
        
        ListNode* store = new ListNode();
        ListNode* temp = store;
        int carry = 0;
        
        while(List1 != NULL || List2 != NULL || carry != NULL){
            int sum = 0;
            if(List1 != NULL){
                sum = sum + List1->val;
                List1 = List1->next;
            }
            if(List2 != NULL){
                sum = sum + List2->val;
                List2 = List2->next;
            }
            sum = sum+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
        }
        
        store = store->next;
        return reverse(store);
    }
};