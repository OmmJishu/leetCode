class Solution {
public:
    int minOperations(int n) {
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += (2*i+1);
        }
        long long target = sum/n;
        int res = 0;
        for(int i = 0; i<n/2; i++){
            res += target-(2*i+1);
        }
        return res;
    }
};