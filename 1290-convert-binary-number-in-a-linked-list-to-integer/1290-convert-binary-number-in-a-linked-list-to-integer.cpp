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
    int getDecimalValue(ListNode* head) {
        vector<int> store;
        ListNode* first = head;
        
        while(first != NULL){
            store.push_back(first->val);
            first = first->next;
        }
        reverse(store.begin(), store.end());
        
        int res = 0;
        int pow = 1;
        for(int i = 0; i<store.size(); i++){
            res = res + store[i]*pow;
            pow = pow*2;
        }
        return res;
    }
};