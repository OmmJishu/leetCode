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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currSum;
        int sum = 0; 
        
        preorder(root, sum, targetSum, currSum);
        return res;
    }
    
private:
    vector<vector<int>> res;
        
    void preorder(TreeNode* root, int sum, int targetSum, vector<int> currSum) {
        if (root == nullptr) 
            return;
        
        sum += root->val;
        currSum.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if(sum == targetSum)
                res.push_back(currSum);
            return;
        }
        
        preorder(root->left, sum, targetSum, currSum);
        preorder(root->right, sum, targetSum, currSum);
    }
};