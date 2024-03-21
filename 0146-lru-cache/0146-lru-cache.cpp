struct Node{ 
    int key;
    int value;
    Node* prev = NULL;
    Node* next = NULL;
    
    Node(int a, int b) : key(a), value(b), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    unordered_map<int,Node*> mp;   // {key, address of Key}
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            Node* node = mp[key];
            int ans = node->value;
            mp.erase(key);
            
            node->prev->next=node->next; // remove
            node->next->prev=node->prev;
            node->next=NULL;
            node->prev=NULL;
            
            node->next = head->next;  // add at front
            node->prev = head; 
            head->next->prev = node;
            head->next = node;
            
            mp[key] = head->next;
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() < capacity){
                Node* newNode = new Node(key,value);
                newNode->next = head->next;  // add at front
                newNode->prev = head; 
                head->next->prev = newNode;
                head->next = newNode;
                mp[key] = head->next;
            }
            else{
                Node* least = tail->prev;
                
                least->prev->next=least->next; // remove
                least->next->prev=least->prev;
                least->next=NULL;
                least->prev=NULL;
                
                mp.erase(least->key);
                
                Node* newNode = new Node(key,value);
                newNode->next = head->next;  // add at front
                newNode->prev = head; 
                head->next->prev = newNode;
                head->next = newNode;
                mp[key] = head->next;
            }
        }
        else{
            Node* currnode = mp[key];
            mp.erase(key);
            currnode->prev->next=currnode->next; // remove
            currnode->next->prev=currnode->prev;
            currnode->next=NULL;
            currnode->prev=NULL;
            
            Node* newNode = new Node(key,value);
            newNode->next = head->next;  // add at front
            newNode->prev = head; 
            head->next->prev = newNode;
            head->next = newNode;
            mp[key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */