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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> res;
        TreeNode* front;
        
        while(!q.empty()){
            if(q.front() != NULL){
                front = q.front();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                q.pop();
            }
            else{
                res.push_back(front->val);
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        return res;
    }
};