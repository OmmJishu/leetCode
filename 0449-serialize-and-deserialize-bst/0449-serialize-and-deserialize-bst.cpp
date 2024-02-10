/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void generateCodes(TreeNode* root, string &code) {
        if(root == NULL) return;
        
        code += to_string(root->val);
        code += "/";
        generateCodes(root->left,code);
        generateCodes(root->right,code);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        generateCodes(root,str);
        return str;
    }
    
    
    // Form BST again
    TreeNode* insert(TreeNode* bst, int num){
        if(bst == NULL){
            return new TreeNode(num);
        }

        if(num < bst->val){
            bst->left = insert(bst->left,num);
        }
        else if(num > bst->val){
            bst->right = insert(bst->right,num);
        }

        return bst;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string curr = "";
        TreeNode* bst = NULL;
        
        for(auto it : data){
            if(it == '/'){
                int num = stoi(curr);
                bst = insert(bst,num);
                curr = "";
                continue;
            }
            curr += it;
        }
        
        return bst;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;