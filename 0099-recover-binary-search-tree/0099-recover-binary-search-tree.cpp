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
    void recoverTree(TreeNode* root) {
        vector<int> temp = compArr(root);
        sort(begin(temp),end(temp));
        
        inorderTrav(root,temp);
    }
    
    private:
    int i = -1;
        
    void inorderTrav(TreeNode* root, vector<int> temp){
        if(root == NULL)
            return;
        
        inorderTrav(root->left,temp);
        i++;
        if(root->val != temp[i]){
            root->val = temp[i];
        }
        inorderTrav(root->right,temp);
    }
    void inorderForArr(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        
        inorderForArr(root->left,res);
        res.push_back(root->val);
        inorderForArr(root->right,res);
    }
    vector<int> compArr(TreeNode* root){
        vector<int> res;
        inorderForArr(root,res);
        return res;
    }
};