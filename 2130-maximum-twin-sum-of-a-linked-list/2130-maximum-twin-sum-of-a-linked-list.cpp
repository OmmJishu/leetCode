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
    int pairSum(ListNode* head) {
        vector<int> store;
        while(head!=NULL){
            store.push_back(head->val);
            head=head->next;
        }
        int mx = INT_MIN, j = store.size()-1;
        for(int i = 0; i<store.size()/2; i++){
            int sum = store[i]+store[j--];
            mx = max(mx,sum);
        }
        return mx;
    }
};