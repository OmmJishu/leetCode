/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int> nums;
        nums.push_back(val);
        preOrder(root,nums);
        sort(nums.begin(),nums.end());
        return build(nums,0,nums.size()-1);
    }
    
    private:
    void preOrder(TreeNode* root,vector<int>& nums){
        if(root == NULL)
            return;
       
        nums.push_back(root->val);
        preOrder(root->left,nums);
        preOrder(root->right,nums);
    }
    
    TreeNode* build(vector<int>& nums, int start, int end){
        if(start>end)
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums,start,mid-1);
        root->right = build(nums,mid+1,end);
        return root;
    }
};