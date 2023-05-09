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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> temp;
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
                res.push_back(temp);
                temp.clear();
            }
            else if(q.empty()){
                res.push_back(temp);
            }
        }
        int sum = 0, i = res.size()-1;
        for(int j = 0; j<res[i].size(); j++){
            sum = sum + res[i][j];
        }
        return sum;
    }
};