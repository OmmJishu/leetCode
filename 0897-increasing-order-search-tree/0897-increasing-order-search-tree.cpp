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
        store.push_back(root->val);
        inorder(root->right,store);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        TreeNode* newRoot = new TreeNode(0);
        TreeNode* temp = newRoot;
        
        for(int i = 0; i<store.size(); i++){
            temp->val = store[i];
            if(i==store.size()-1)
                break;
            temp->left = NULL;
            temp->right = new TreeNode(0);
            temp = temp->right;
        }
        return newRoot;
    }
};