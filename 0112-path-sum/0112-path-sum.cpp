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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0; 
        preorder(root, sum, targetSum);
        return find;
    }
 
private:
    bool find = false;
        
    void preorder(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) 
            return;
        
        sum += root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if(sum == targetSum)
                find = true;
            return;
        }
        
        preorder(root->left, sum, targetSum);
        preorder(root->right, sum, targetSum);
    }
};