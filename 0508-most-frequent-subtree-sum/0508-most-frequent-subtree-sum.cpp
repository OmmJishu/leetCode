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
    
    int solve(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int sum = 0;
        sum += solve(root->left) + solve(root->right) + root->val;   
        mp[sum]++;
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        
        int mx = INT_MIN;
        for(auto it : mp)
            mx = max(mx,it.second);
        
        vector<int> res;
        for(auto it : mp){
            if(it.second == mx)
                res.push_back(it.first);
        }
        
        return res;
    }
};