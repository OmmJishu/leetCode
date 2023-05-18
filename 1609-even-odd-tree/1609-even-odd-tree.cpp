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
    int a = 0;
    bool isEvenOddTree(TreeNode* root) {
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
            else if(!q.empty() && front == NULL){
                q.push(NULL);
                if(a%2 == 0){
                    a++;
                    for(int i = 0; i<temp.size()-1; i++){
                        if(temp[i]>=temp[i+1] || temp[i]%2 == 0)
                            return false;
                    }
                    if(temp[temp.size()-1]%2 == 0)
                        return false;
                }
                else if(a%2 == 1){
                    a++;
                    for(int i = 0; i<temp.size()-1; i++){
                        if(temp[i]<=temp[i+1] || temp[i]%2 != 0)
                            return false;
                    }
                    if(temp[temp.size()-1]%2 != 0)
                        return false;
                }
                temp.clear();
            }
            else if(q.empty()){
                if(a%2 == 0){
                    a++;
                    for(int i = 0; i<temp.size()-1; i++){
                        if(temp[i]>=temp[i+1] || temp[i]%2 == 0)
                            return false;
                    }
                    if(temp[temp.size()-1]%2 == 0)
                        return false;
                }
                else if(a%2 == 1){
                    a++;
                    for(int i = 0; i<temp.size()-1; i++){
                        if(temp[i]<=temp[i+1] || temp[i]%2 != 0)
                            return false;
                    }
                    if(temp[temp.size()-1]%2 != 0)
                        return false;
                }
            }
        }
        return true;
    }
};