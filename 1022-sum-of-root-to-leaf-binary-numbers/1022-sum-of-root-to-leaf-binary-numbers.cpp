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
    void preorder(TreeNode* root, string s, vector<string>& store) {
        if (root == nullptr) 
            return;
        
        s += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            store.push_back(s);
            return;
        }
        
        preorder(root->left, s, store);
        preorder(root->right, s, store);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<string> store;
        string s = ""; 
        
        preorder(root, s, store);
        
        int ans = 0;
        for(auto it : store){
            int num = 0, j = 0;
            for(int i = it.size()-1; i>=0; i--){
                if(it[i]-'0' == 1)
                    num = num + pow(2,j);
                j++;
            }
            cout<<num<<" ";
            ans += num;
        }
        
        return ans;
    }
};