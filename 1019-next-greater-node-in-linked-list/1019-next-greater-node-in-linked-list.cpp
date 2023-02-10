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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* h1 = head;
        vector<int> answer;
        
        while(h1 != NULL){
            ListNode* h2 = h1;
            int count = 0;
            while(h2 != NULL){
                if(h2->val > h1->val){
                    answer.push_back(h2->val);
                    count++;
                    break;
                }
                else
                    h2 = h2->next;
            }
            if(count == 0){
                answer.push_back(0);
            }
            h1 = h1->next;
        }
        return answer;
    }
};