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
private:
    TreeNode* root = NULL;
    TreeNode* insert(TreeNode* root, int num){
        if(root == NULL){
            return new TreeNode(num);
        }

        if(num < root->val){
            root->left = insert(root->left,num);
        }
        else if(num > root->val){
            root->right = insert(root->right,num);
        }

        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        for(auto it : preorder){
            root = insert(root,it);
        }
        return root;
    }
};