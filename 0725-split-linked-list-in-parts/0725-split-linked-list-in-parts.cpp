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
    int findSize(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int length = findSize(head);
        ListNode* temp = head;
        
        if(length <= k){
            int count = 0;
            while(temp!=NULL){
                ListNode* a = new ListNode(temp->val);
                res.push_back(a);
                temp = temp->next;
                count++;
            }
            int rem = k - length;
            while(rem){
                res.push_back(NULL);
                rem--;
            }
        }
        
        int nodesLen = length/k, left = length%k;
        int times = nodesLen*k;
        
        if(length > k){
            int cnt = 0;
            while(times){
                int c = nodesLen;
                ListNode* a = new ListNode();
                ListNode* b = a;
                ListNode* r = b;
                while(c){
                    b->val = temp->val;
                    ListNode* nextNode = new ListNode();
                    b->next = nextNode;
                    b = nextNode;
                    temp = temp->next;
                    c--;
                    times--;
                    cnt++;
                }
                if(left>0){
                    b->val = temp->val;
                    ListNode* nextNode = new ListNode();
                    b->next = nextNode;
                    b = nextNode;
                    temp = temp->next;
                    left--;
                }
                
                while(r->next->next != NULL)
                    r = r->next;
                r->next = NULL;
                
                res.push_back(a);
            }
        }
        return res;
    }
};