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
    void inorder(TreeNode* root, vector<int> &nums){
        if(root == NULL)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(k - nums[i]) != mp.end()){
                int index1 = i;
                int index2 = mp[k - nums[i]];
                if(index1 != index2)
                    return true;
            }   
            mp[nums[i]] = i;
        }
        return false;
    }
};