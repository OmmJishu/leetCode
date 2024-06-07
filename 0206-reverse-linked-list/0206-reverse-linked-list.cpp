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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        
        vector<ListNode*> nums;
        while(head){
            nums.push_back(head);
            head = head->next;
        }
        
        for(int i = nums.size()-1; i>=1; i--){
            nums[i]->next = nums[i-1];
        }
        nums[0]->next = NULL;
        
        return nums[nums.size()-1];
    }
};