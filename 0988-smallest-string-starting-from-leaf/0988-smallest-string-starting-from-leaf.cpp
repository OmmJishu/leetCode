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
    string smallestFromLeaf(TreeNode* root) {
        for(int i = 0; i<26; i++)
            mp[i] = 'a' + i;
    
        vector<string> store;
        string s = ""; 
        
        preorder(root, s, store);
        sort(store.begin(),store.end());
    
        return store[0];
    }

private:
    map<int,char> mp;
    
    void preorder(TreeNode* root, string s, vector<string>& store) {
        if (root == nullptr) 
            return;
        
        s += mp[root->val];
        
        if (root->left == NULL && root->right == NULL) {
            reverse(s.begin(),s.end());
            store.push_back(s);
            return;
        }
        
        preorder(root->left, s, store);
        preorder(root->right, s, store);
    }
};