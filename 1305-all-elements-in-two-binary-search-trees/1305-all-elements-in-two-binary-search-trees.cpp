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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums;
        preOrder(root1,nums);
        preOrder(root2,nums);
        sort(nums.begin(),nums.end());
        return nums;
    }
    
    private:
    void preOrder(TreeNode* root,vector<int>& nums){
        if(root == NULL)
            return;
       
        nums.push_back(root->val);
        preOrder(root->left,nums);
        preOrder(root->right,nums);
    }
};