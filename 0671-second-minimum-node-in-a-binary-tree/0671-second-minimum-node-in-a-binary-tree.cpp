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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
    
        set<int> st;
        while(!q.empty()){
            TreeNode* front = q.front();
                q.pop();
            if(front != NULL){
                st.insert(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            else if(!q.empty()){
                q.push(NULL);
            }
        }
    
        vector<int> st2;
        for(auto it : st)
            st2.push_back(it);
        sort(st2.begin(),st2.end());
        
        if(st.size()==1)
            return -1;
        
        return st2[1];
    }
};