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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp = "";
        
        solve(root,temp,res);
        
        return res;
    }

private:
    void solve(TreeNode* root, string temp, vector<string>& res){
        if(root == NULL){
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            res.push_back(temp);
            temp += "->";
        } 
        
        temp += to_string(root->val) + "->";
        
        if(root->left)
            solve(root->left, temp, res);
        if(root->right)
            solve(root->right, temp, res);
    }
};