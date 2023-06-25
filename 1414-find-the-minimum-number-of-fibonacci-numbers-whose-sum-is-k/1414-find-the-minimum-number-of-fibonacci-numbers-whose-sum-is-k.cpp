class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> store;
        store.push_back(0);
        store.push_back(1);
        
        while(store[store.size()-1] <= k)
            store.push_back(store[store.size()-1]+store[store.size()-2]);
        
        for(auto it : store) cout<<it<<" ";
        
        int cnt = 0,i = store.size()-1;
        while(i >= 0 && k != 0){
            if(k - store[i] >= 0){
                k = k - store[i];
                cnt++;
            }
            i--;
        }
        
        return cnt;
    }
};