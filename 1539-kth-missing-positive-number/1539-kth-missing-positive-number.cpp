class Solution {
public:
    bool find(vector<int> &arr, int n){
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == n)
                return true;
        }
        return false;
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> store;
        int n = arr.size();
        
        for(int i = 1; i<=arr[n-1]; i++){
            if(find(arr,i))
                continue;
            else
                store.push_back(i);
        }
        for(int p = arr[n-1]+1; p<=5000; p++)
            store.push_back(p);
        
        return store[k-1];
    }
};