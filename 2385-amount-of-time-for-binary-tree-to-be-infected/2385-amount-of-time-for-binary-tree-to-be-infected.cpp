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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_Track;
        markParent(root,parent_Track);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        TreeNode* target;
        findStart(root,start,target);
        q.push(target);
        
        visited[target] = true;
        int count = 0;
        
        while(!q.empty()){
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
            count++;
        }
        
        return count-1;
    }
    
private:
    void findStart(TreeNode* root, int start, TreeNode* &target){
        if(root == NULL)
            return;
        
        if(root->val == start)
            target = root;
        
        findStart(root->left,start,target);
        findStart(root->right,start,target);
    }
    
    
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