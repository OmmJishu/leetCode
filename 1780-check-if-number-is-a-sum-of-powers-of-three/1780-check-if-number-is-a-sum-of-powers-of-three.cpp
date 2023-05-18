class Solution {
public:
    bool checkPowersOfThree(int n) {
        stack<int> store;
        int a = 1;
        while(a<=n){
            store.push(a);
            a = a*3;
        }
        long sum = 0;
        while(!store.empty()){
            if(sum + store.top() <= n){
                sum += store.top();
            }
            store.pop();
        }
        
        return sum == n;
    }
};