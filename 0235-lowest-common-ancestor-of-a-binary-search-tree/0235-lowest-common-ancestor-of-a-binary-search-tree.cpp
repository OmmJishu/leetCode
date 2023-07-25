/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* head = root;
        vector<TreeNode*> arr1,arr2;
        
        getPath(root,arr1,p);
        getPath(head,arr2,q);
        
        TreeNode* res = new TreeNode();
        int m = min(arr1.size(),arr2.size());
        
        for(int i = 0; i<m; i++){
            if(arr1[i]->val != arr2[i]->val){
                res = arr1[i-1];
                break;
            }
            if(arr1[i]->val == arr2[i]->val  && i == m-1)
                res = arr1[i];
        }
        
        return res;
    }
    
private:
    bool getPath(TreeNode* root, vector<TreeNode*>& arr1, TreeNode* p){
        if(root == NULL){
            return false;
        }
        
        arr1.push_back(root);
        if(root == p){
            return true;
        }
        
        if((getPath(root->left,arr1,p) == true) || (getPath(root->right,arr1,p) == true))
            return true;
        else
            arr1.pop_back();
        
        return false;
    }
};