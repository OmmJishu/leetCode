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
    // post-order 
private:
    pair<int,int> fun(TreeNode* root, int &res){
        if(root == NULL)
            return {INT_MAX,INT_MIN};
        
        auto [leftMin, leftMax] = fun(root->left, res);
        auto [rightMin, rightMax] = fun(root->right, res);
        
        int currMin = min(leftMin, min(root->val,rightMin));
        int currMax = max(rightMax, max(root->val, leftMax));
        
        res = max(res, max(abs(root->val - currMin), abs(currMax - root->val)));
        
        return {currMin, currMax};
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        fun(root,res);
        
        return res;
    }
};