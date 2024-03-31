struct Node{
    int key, value, cnt;
    Node* prev = NULL;
    Node* next = NULL;
    
    Node(int a, int b) : key(a), value(b), prev(NULL), next(NULL), cnt(1) {}
};

struct List{
    int size;
    Node* head;
    Node* tail;
    
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        size--;
    }
};


class LFUCache {
private:
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;
    
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        currSize = 0; 
    }
    
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        node->cnt += 1;
        if(freqListMap.find(node->cnt) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt];
        }
        
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int res = node->value;
            updateFreqListMap(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(currSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--; 
            }
            
            currSize++;
            // new value has to be added who is not there previously  so minFreq = 1
            minFreq = 1; 
            
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */