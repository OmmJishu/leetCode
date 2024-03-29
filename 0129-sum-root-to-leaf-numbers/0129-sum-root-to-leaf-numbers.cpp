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
    void preorder(TreeNode* root, string s, vector<int>& store) {
        if (root == nullptr) 
            return;
        
        s += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            store.push_back(stoi(s));
            return;
        }
        
        preorder(root->left, s, store);
        preorder(root->right, s, store);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> store;
        string s = ""; 
        
        preorder(root, s, store);
        int sum = accumulate(store.begin(),store.end(),0);
        
        return sum;
    }
};