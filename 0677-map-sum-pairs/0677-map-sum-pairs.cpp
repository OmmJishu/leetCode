struct Node{
    vector<Node*> links;
    // Node* links[26];
    int value = 0;
    
    Node() : links(26, NULL) {}
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class MapSum {
    private:
    unordered_map<string,int> mp;
    Node* root;
    
public:
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* node = root;
        
        for(int i = 0; i<key.size(); i++){
            if(node->containsKey(key[i]) == false){
                node->put(key[i],new Node());
            }
            node = node->get(key[i]);
            node->value += (val - mp[key]); // remove old value and add new value
        }
        
        mp[key] = val;
    }
    
    int sum(string prefix) {
        Node* node = root;
        int res = 0;
        
        for(int i = 0; i<prefix.size(); i++){
            if(node->containsKey(prefix[i]) == false){
                return 0;
            }
            node = node->get(prefix[i]);
            res = node->value;
        }
        
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */