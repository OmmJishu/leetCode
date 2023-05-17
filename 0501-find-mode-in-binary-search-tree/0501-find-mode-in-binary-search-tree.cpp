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
    unordered_map<int,int> mp;
    
    vector<int> findMode(TreeNode* root) {
        int maxi = INT_MIN;
        inorder(root,maxi);
        
        vector<int> res;
        for(auto it : mp)
            if(it.second == maxi)
                res.push_back(it.first);
        return res;
    }
    private:
    void inorder(TreeNode* root, int &maxi){
        if(root == NULL)
            return;
        inorder(root->left,maxi);
        mp[root->val]++;
        maxi = max(maxi,mp[root->val]);
        inorder(root->right,maxi);
    }
};