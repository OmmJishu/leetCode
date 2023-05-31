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
    int widthOfBinaryTree(TreeNode* root) {
        if(root ==  NULL)
            return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            int minofLevel = q.front().second;
            int first,last;
            for(int i = 0; i<sz; i++){
                TreeNode* front = q.front().first;
                unsigned long long curr = q.front().second-minofLevel;
                q.pop();
                
                if(i==0)
                    first = curr;
                if(i==sz-1)
                    last = curr;
                
                if(front->left)
                    q.push({front->left, curr*2+1});
                if(front->right)
                    q.push({front->right, curr*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};