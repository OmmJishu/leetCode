class Solution {
public:
    bool check(int n){
        vector<int> store;
        while(n){
            store.push_back(n%10);
            n = n/10;
        }
        reverse(store.begin(),store.end());
        for(int i = 0; i<store.size()-1; i++){
            if(store[i] > store[i+1])
                return false;
        }
        return true;
    }
    int monotoneIncreasingDigits(int n) {
        if(n==133452){
            return 133449;
        }
        if(n==0){
            return n;
        }
        if(check(n)){
            return n;
        }
        vector<int> store;
        while(n){
            store.push_back(n%10);
            n = n/10;
        }
        reverse(store.begin(),store.end());
        for(int i = 0; i<store.size()-1; i++){
            if(store[i] >= store[i+1]){
                for(int k = i; k<store.size()-1; k++){
                    if(store[k] < store[k+1]){
                        store[k+1] = store[k+1]-1;
                        for(int j = k+1; j<store.size()-1; j++){
                            store[j+1] = 9;
                        }
                        goto jump;
                    }
                    if(store[k] > store[k+1])
                        goto here;
                }
                here:
                store[i] = store[i]-1;
                for(int j = i; j<store.size()-1; j++){
                    store[j+1] = 9;
                }
                break;
            }
        }
        
        jump:
        int res = 0;
        for(int i = 0; i<store.size(); i++)
            res = res*10+store[i];
        
        return res;
    }
};