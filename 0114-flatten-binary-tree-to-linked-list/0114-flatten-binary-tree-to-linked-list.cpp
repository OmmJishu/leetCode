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
    void preOrder(TreeNode* root, vector<TreeNode*> &res){
        if(root == NULL)
            return;
        res.push_back(root);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        preOrder(root, res);
        if(res.size()==0)
            return;
        
        TreeNode* temp = res[0];
        temp->left = NULL;
        temp->right = NULL;
        
        for(int i=1; i<res.size(); i++){
            TreeNode* curr= res[i];
            temp->right = curr;
            curr->left =NULL;
            curr->right = NULL;
            temp = curr;
        }
    }
};