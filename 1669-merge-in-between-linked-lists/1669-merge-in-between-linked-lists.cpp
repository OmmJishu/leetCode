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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first2 = list2;

        ListNode* curr = list1;
        ListNode* prev = NULL;
        
        int count = 0;
        while(curr != NULL){
            if(count < a)
                prev = curr;
            if(count == a)
                prev->next = first2;
            
            if(count == b){
                while(first2->next != NULL){
                    if(first2->next == NULL){
                        first2->next = curr->next;
                        break;
                    }
                    first2 = first2->next;
                }
                first2->next = curr->next;
                break;
            }
            curr = curr->next;
            count++;
        }
        return list1;
    }
};