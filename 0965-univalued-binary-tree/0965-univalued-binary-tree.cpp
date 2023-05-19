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
        if(root==NULL)
            return;
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        for(int i = 0; i<store.size()-1; i++)
            if(store[i] != store[i+1])
                return false;
        return true;
    }
};