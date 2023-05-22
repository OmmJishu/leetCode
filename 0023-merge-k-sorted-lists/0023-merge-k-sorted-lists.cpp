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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        map<int,int> mp;
        for(int i = 0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                mp[temp->val]++;
                temp = temp->next;
            }
        }
        if(mp.size()==0)
            return NULL;
        
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        ListNode* curr = newHead;
        
        for(auto it : mp){
            int a = it.second;
            while(a--){
                temp->val = it.first;
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        curr->next = NULL;
        return newHead;
    }
};