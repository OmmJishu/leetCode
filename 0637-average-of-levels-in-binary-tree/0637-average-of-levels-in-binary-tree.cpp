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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<double> temp;
        while(!q.empty()){
            TreeNode* front = q.front();
                q.pop();
            if(front != NULL){
                temp.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            else if(!q.empty()){
                q.push(NULL);
                double sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum/temp.size());
                temp.clear();
            }
            else if(q.empty()){
                double sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum/temp.size());
            }
        }
        return res;
    }
};