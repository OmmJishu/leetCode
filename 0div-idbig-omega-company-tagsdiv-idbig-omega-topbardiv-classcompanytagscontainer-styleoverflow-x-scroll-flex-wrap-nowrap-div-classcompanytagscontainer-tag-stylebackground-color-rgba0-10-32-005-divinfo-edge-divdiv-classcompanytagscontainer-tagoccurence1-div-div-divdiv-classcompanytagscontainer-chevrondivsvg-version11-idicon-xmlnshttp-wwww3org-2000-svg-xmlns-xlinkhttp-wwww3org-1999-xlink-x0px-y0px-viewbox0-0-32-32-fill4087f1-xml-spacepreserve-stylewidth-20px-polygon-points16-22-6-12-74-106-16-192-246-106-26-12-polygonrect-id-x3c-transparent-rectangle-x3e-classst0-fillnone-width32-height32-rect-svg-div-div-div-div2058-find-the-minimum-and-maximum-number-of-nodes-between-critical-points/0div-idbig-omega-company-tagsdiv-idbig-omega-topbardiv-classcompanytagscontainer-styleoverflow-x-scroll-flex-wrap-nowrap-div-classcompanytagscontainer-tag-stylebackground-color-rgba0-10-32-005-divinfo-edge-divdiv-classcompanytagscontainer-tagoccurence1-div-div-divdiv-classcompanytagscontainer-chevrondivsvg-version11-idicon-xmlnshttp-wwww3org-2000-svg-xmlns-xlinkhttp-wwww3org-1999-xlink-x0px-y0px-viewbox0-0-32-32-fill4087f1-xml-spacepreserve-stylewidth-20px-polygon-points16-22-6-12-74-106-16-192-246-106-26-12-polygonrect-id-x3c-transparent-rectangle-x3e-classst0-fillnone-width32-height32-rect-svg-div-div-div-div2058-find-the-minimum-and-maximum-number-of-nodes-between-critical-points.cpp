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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        
        vector<int> arr;
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                arr.push_back(i);
            }
            if(nums[i-1]>nums[i] && nums[i]<nums[i+1]){
                arr.push_back(i);
            }
        }
        
        if(arr.size()<2){
            return {-1,-1};
        }
        
        int maxiDist = arr[arr.size()-1] - arr[0];
        int miniDist = INT_MAX;
        for(int i = 1; i<arr.size(); i++){
            miniDist = min(miniDist,(arr[i]-arr[i-1]));
        }

        return {miniDist,maxiDist};
    }
};