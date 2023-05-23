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
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> nums;
        preOrder(root,nums,key);
        sort(nums.begin(),nums.end());
        return build(nums,0,nums.size()-1);
    }
    
    private:
     void preOrder(TreeNode* root,vector<int>& nums,int key){
        if(root == NULL)
            return;
        if(root->val!=key)
            nums.push_back(root->val);
        preOrder(root->left,nums,key);
        preOrder(root->right,nums,key);
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