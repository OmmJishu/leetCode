class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = accumulate(gas.begin(),gas.end(),0);
        int costSum = accumulate(cost.begin(),cost.end(),0);
        if(sumGas < costSum)
            return -1;
        
        int total = 0; 
        int startIdx = 0;
        for(int i = 0; i<gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                startIdx = i+1;
                total = 0;
            }
        }
        
        return startIdx;
    }
};
