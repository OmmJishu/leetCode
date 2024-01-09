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
    void inorder(TreeNode* root, vector<int>& store){
        if(root == NULL)
            return;
        inorder(root->left,store);
        if(root->left == NULL && root->right == NULL)
            store.push_back(root->val);
        inorder(root->right,store);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1,store2;
        inorder(root1,store1);
        inorder(root2,store2);
        if(store1 == store2)
            return true;
        return false;
    }
};