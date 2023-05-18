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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        while(temp!=NULL){
            store.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0; i<store.size(); i++){
            int sum = 0;
            for(int j = i; j<store.size(); j++){
                sum = sum + store[j];
                if(sum == 0){
                    store.erase(store.begin()+i,store.begin()+j+1);
                    i--;
                    break;
                }
            }
        }
        ListNode* newHead = new ListNode(0);
        ListNode* Temp2 = newHead;
        for(int i = 0; i<store.size(); i++){
            Temp2->next = new ListNode(store[i]);
            Temp2 = Temp2->next;
        }
        return newHead->next;
    }
};