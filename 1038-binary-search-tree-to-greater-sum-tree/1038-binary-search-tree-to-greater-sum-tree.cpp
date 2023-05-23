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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        int sum = 0;
        for(auto it : nums)
            sum += it;
        for(int i = 0; i<nums.size(); i++){
            int temp = nums[i];
            nums[i] = sum;
            sum = sum - temp;
        }
        update(root,nums);
        return root;
    }
    
    private:
    void inorder(TreeNode* root,vector<int>& nums){
        if(root == NULL)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    int i = 0;
    void update(TreeNode* root,vector<int>& nums){
        if(root == NULL)
            return;
        update(root->left,nums);
        root->val = nums[i++];
        update(root->right,nums);
    }
};