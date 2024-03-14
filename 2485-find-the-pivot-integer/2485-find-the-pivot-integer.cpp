class Solution {
public:
    int pivotInteger(int n) {
        // int sum1 = 0;
        int add = (n*(n+1))/2;
        int ans = -1;

        for(int i = 1; i<=n; i++){
            int sum1 = (i*(i+1))/2;
            int sum2 = add - sum1 + i;
            if(sum1 == sum2){
                ans = i;
                break;
            }
        }
        return ans;
    }
};