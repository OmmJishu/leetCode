class Solution {
public:
    int splitNum(int num) {
        vector<int> store;
        while(num){
            store.push_back(num%10);
            num = num/10;
        }
        sort(store.begin(),store.end());
        int num1 = 0, num2 = 0;
        for(int i = 0; i<store.size(); i=i+2)
            num1 = num1*10+store[i];
        for(int i = 1; i<store.size(); i=i+2)
            num2 = num2*10+store[i];
        
        return num1+num2;
    }
};