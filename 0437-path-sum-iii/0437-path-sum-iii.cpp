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
using ull = unsigned long long;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<TreeNode*> nums;
        pre(root,nums);
        
        
        for(int i = 0; i<nums.size(); i++){
            preorder(nums[i],0,targetSum);
        }
        
        return cnt;
    }
    
private:
    
    void pre(TreeNode* root, vector<TreeNode*> &nums){
        if(root == NULL){
            return;
        }
        nums.push_back(root);
        pre(root->left,nums);
        pre(root->right,nums );
    }
    
    
int cnt = 0;

void preorder (TreeNode* root, ull sum, int targetSum) { 
    if (root == nullptr)
        return;

    sum += root->val;
    if(sum == targetSum) { 
        cnt++;
    }

   preorder (root->left, sum, targetSum); 
   preorder(root->right, sum, targetSum);                                  }
};