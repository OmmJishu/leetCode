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
    ListNode* doubleIt(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        
        while(temp){
            store.push_back(temp->val);
            temp = temp->next;
        }
        reverse(store.begin(),store.end());
        
        int rem = 0;
        for(int i = 0; i<store.size(); i++){
            int num = (store[i]*2 + rem) % 10;
            rem = (store[i]*2 + rem) / 10;
            store[i] = num;
        }
        
        if(rem != 0){
            store.push_back(rem);
        }
            
        int i = 0;
        reverse(store.begin(),store.end());
        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;
        
        while(i<store.size()){
            ListNode* nxt = new ListNode(store[i++]);
            curr->next = nxt;
            curr = curr->next;
        }
        
        return newHead->next;
    }
};