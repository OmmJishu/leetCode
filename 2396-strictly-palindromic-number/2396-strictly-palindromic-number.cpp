class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i = 2; i <= n-2; i++){
            vector<int> store;
            int temp = n;
            while(temp){
                store.push_back(temp % i);
                temp = temp / i;
            }
            for(int x = 0, y = store.size()-1; x<store.size()/2; x++,y--)
                if(store[x] != store[y])
                    return false;
        }
        return true;
    }
};