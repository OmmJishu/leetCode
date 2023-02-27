class Solution {
public:
    int tribonacci(int n) {
        vector<int> store;
        
        store.push_back(0);
        store.push_back(1);
        store.push_back(1);
        
        for(int i = 3; i<=n; i++){
            store.push_back(store[i-3] + store[i-2] + store[i-1]);
        }
        return store[n];
    }
};