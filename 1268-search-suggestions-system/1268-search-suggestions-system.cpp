struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setFlag(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Solution {
private:
    Node* root;
public:
    Solution(){
        root = new Node();
    }
    
    void insert(string& word){
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setFlag();
    }
    
    
    vector<vector<string>> res;
    void searchPref(string &word){
        Node* node = root;
        vector<string> tmp;
        
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                res.push_back({});
                return;
            }
            node = node->get(word[i]);
        }
        
        dfs(node,word,tmp); 
        
        res.push_back(tmp);
    }
    
    void dfs(Node* node, string word, vector<string>& tmp){
        if(tmp.size() == 3) return;
        if(node->isEnd()) tmp.push_back(word);
      
        for(char ch = 'a'; ch<='z'; ch++)
            if(node->containsKey(ch) == true)
                dfs(node->get(ch),word + ch,tmp);
    }
    
    
    // main function
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(auto it : products)
            insert(it);
        
        string pref = "";
        for(auto it : searchWord){
            pref += it;
            searchPref(pref);
        }
        
        return res;
    }
};