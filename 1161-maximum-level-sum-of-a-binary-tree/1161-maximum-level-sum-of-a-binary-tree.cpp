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
    int maxLevelSum(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return 1;
        
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
                int sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum);
                temp.clear();
            }
            else if(q.empty()){
                int sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum);
            }
        }
        int mxNum = INT_MIN;
        for(int i = 0; i<res.size(); i++){
            mxNum = max(mxNum, res[i]);
        }
        for(int i = 0; i< res.size(); i++){
            if(mxNum == res[i])
                return i+1;
        }
        return 1;
    }
};