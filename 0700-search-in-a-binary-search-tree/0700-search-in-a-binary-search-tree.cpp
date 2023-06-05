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
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<int> store;
        TreeNode* newRoot = new TreeNode();
        int count = 0;
        
        preorder(root,val,newRoot,count);
        if(count == 0)
            return NULL;

        return newRoot;
    }
    
private:
    void preorder(TreeNode* root, int val, TreeNode* &newRoot, int &count){
        if(root == NULL)
            return;
        if(root->val == val){
            newRoot = root;
            count++;
        }
        
        preorder(root->left,val,newRoot,count);
        preorder(root->right,val,newRoot,count);
    }
};