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
    void inorder(TreeNode* root1, vector<int>& store1){
        if(root1 == NULL)
            return;
        inorder(root1->left,store1);
        if(root1->left == NULL && root1->right == NULL)
            store1.push_back(root1->val);
        inorder(root1->right,store1);
    }
    void inorder2(TreeNode* root2, vector<int>& store2){
        if(root2 == NULL)
            return;
        inorder2(root2->left,store2);
        if(root2->left == NULL && root2->right == NULL)
            store2.push_back(root2->val);
        inorder2(root2->right,store2);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1,store2;
        inorder(root1,store1);
        inorder2(root2,store2);
        if(store1 == store2)
            return true;
        return false;
    }
};