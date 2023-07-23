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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* curr = head;
        ListNode* temp = head;
        
        int i = 0; 
        vector<int> store;
        while(temp != NULL){
            i++;
            if(i >= left && i <= right){
                store.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        reverse(store.begin(),store.end());
        
        i = 0;
        int j = 0;
        while(curr != NULL){
            i++;
            if(i >= left && i <= right){
                curr->val = store[j++];
            }
            curr = curr->next;
        }
        
      
        return head;
    }
};