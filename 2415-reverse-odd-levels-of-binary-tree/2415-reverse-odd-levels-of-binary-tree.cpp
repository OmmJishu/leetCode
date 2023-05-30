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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> arr;
            queue<TreeNode*> tempq;
            
            for(int i = 0; i<sz; i++){
                TreeNode* front = q.front();
                tempq.push(front);
                arr.push_back(front->val);
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            
            if(count%2 == 1){
                reverse(arr.begin(),arr.end());
                int p = 0;
                while(!tempq.empty()){
                    TreeNode* curr = tempq.front();
                    curr->val = arr[p++];
                    tempq.pop();
                }
            }
            count++;
        }
        return root;
    }
};