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
    vector<int> insertionSort(vector<int> &arr){
        int curr, j;
        for (int i = 1; i < arr.size(); i++){
            curr = arr[i];
            j = i - 1;
 
            while (j >= 0 && arr[j] > curr){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = curr;
        }
        return arr;
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int> temp;
        while(head != NULL){
            temp.push_back(head->val);
            head = head->next;
        }
        insertionSort(temp);
        
        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;
        ListNode* first = curr;
        for(int i = 0; i<temp.size(); i++){
            ListNode* nextNode = new ListNode();
            curr->val = temp[i];
            curr->next = nextNode;
            curr = nextNode;
        }
        
        while(first->next->next != NULL)
            first = first->next;
        first->next = NULL;
        
        return newHead;
    }
};