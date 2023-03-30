class Solution {
public:
    bool isPrime(int n){
        if (n == 1)
            return false;
        int i = 2;
        while(i*i <= n){
            if (n % i == 0)
                return false;
            i++;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left == 1 && right == 1)
            return {-1,-1};
        vector<int> store;
        for(int i = left; i<=right; i++){
            if(isPrime(i))
                store.push_back(i);
        }
        if(store.size() == 0)
            return {-1,-1};
        int diff = INT_MAX;
        vector<int> res(2,-1);
        for(int i = 0; i<store.size()-1; i++){
            if(store[i+1]-store[i] < diff){
                diff = store[i+1]-store[i];
                res[0] = store[i];
                res[1] = store[i+1];
            }
        }
        return res;
    }
};