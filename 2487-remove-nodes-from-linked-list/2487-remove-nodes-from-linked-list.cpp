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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = reverseList(head);
        
        ListNode* newHead = new ListNode(temp->val);
        ListNode* res = newHead;
        int mx = temp->val;
        temp = temp -> next;
        while(temp != NULL){
            if(temp->val >= mx){
                newHead -> next = new ListNode(temp->val);
                newHead = newHead->next;
                mx = temp->val;
            }
            temp = temp->next;
        }
        
        res = reverseList(res);
        return res;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* tempHead = NULL;
        
        while(head != NULL){
            ListNode* next = head->next;
            head->next = tempHead;
            tempHead = head;
            head = next;
        }
        
        return tempHead;
    }
};