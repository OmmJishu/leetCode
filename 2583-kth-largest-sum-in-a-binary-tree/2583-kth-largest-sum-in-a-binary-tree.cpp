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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        if(root == NULL)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<long long> temp;
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
                unsigned long long int sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum);
                temp.clear();
            }
            else if(q.empty()){
                unsigned long long int sum = 0;
                for(int k = 0; k<temp.size(); k++)
                    sum = sum + temp[k];
                res.push_back(sum);
            }
        }
        sort(res.begin(),res.end());
        if(k <= res.size())
            return res[res.size()-k];
        return -1;
    }
};