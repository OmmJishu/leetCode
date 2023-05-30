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
    void preorder(TreeNode* root, string &res){
        if(root == NULL)
            return;
        
        res = res + to_string(root->val);
        if(root->left != NULL){
            res = res + '(';
            preorder(root->left,res);
            res = res + ')';
        }
        if(root->right != NULL){
            if(root->left == NULL)
                res = res + "()";
            res = res + '(';
            preorder(root->right,res);
            res = res + ')';
        }
    }
    string tree2str(TreeNode* root) {
        string res = "";
        preorder(root,res);
        return res;
    }
};