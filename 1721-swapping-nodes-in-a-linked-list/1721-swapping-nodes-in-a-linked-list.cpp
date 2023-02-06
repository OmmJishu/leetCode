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
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int> store;
        ListNode* first = head;
        while(first != NULL){
            store.push_back(first->val);
            first = first->next;
        }
        
        int n = store.size();
        for(int i = 0, j = n-1; i<n, j>=0; i++, j--){
            if(i == k-1){
                int temp = store[i];
                store[i] = store[j];
                store[j] = temp;
            }
        }
        
        ListNode* first1 = head;
        for(int i = 0; i<n; i++){
            first1->val = store[i];
            first1 = first1->next;
        }
        return head;
    }
};