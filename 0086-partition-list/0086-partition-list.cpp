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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        
        ListNode* res = new ListNode();
        ListNode* newHead = res;

        ListNode* temp = head;
        vector<int> store;
        
        while(temp != NULL){
            if(temp->val < x){
                newHead->val = temp->val;
                ListNode* nxt = new ListNode();
                newHead->next = nxt;
                newHead = nxt;
            }
            else
                store.push_back(temp->val);
            temp = temp->next;
        }
        
        
        ListNode* curr = res;
        while(curr->next != NULL)
            curr = curr->next;
        
        for(int i = 0; i<store.size(); i++){
            ListNode* nxt = new ListNode();
            curr->next = nxt;
            curr->val = store[i];
            curr = nxt;
        }
        
        ListNode* ans = res;
        while(ans->next->next != NULL)
            ans = ans->next;
        ans->next = NULL;
        
        return res;
    }
};