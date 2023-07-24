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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_Track;
        markParent(root,parent_Track);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_Level = 0;
        
        while(!q.empty()){
            if(curr_Level++ == k){
                break;
            }
            int sz = q.size();
            
            for(int i = 0; i<sz; i++){
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left && visited[current->left] == false){
                    visited[current->left] = true;
                    q.push(current->left);
                }
                
                if(current->right && visited[current->right] == false){
                    visited[current->right] = true;
                    q.push(current->right);
                }
                
                if(parent_Track[current] && visited[parent_Track[current]] == false){
                    visited[parent_Track[current]] = true;
                    q.push(parent_Track[current]);
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        
        return res;
    }
    
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_Track){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            
            if(current->left){
                parent_Track[current->left] = current;
                q.push(current->left);
            }
            
            if(current->right){
                parent_Track[current->right] = current;
                q.push(current->right);
            }
        }
    }
};