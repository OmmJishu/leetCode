class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> store;
        for(int i = 0; i<numOnes; i++)
            store.push_back(1);
        for(int i = 0; i<numZeros; i++)
            store.push_back(0);
        for(int i = 0; i<numNegOnes; i++)
            store.push_back(-1);
        
        int sum = 0;
        
        for(int i = 0; i<k; i++){
            sum = sum+store[i];
        }
        return sum;
    }
};