class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> store;
        while(n>0){
            store.push_back(n%2);
            n = n/2;
        }
        int countEven = 0, countOdd = 0;
        for(int i = 0; i<store.size(); i++){
            if(i%2 == 0 && store[i] == 1)
                countEven++;
            else if(i%2 != 0 && store[i] == 1)
                countOdd++;
        }
        return {countEven, countOdd};;
    }
};