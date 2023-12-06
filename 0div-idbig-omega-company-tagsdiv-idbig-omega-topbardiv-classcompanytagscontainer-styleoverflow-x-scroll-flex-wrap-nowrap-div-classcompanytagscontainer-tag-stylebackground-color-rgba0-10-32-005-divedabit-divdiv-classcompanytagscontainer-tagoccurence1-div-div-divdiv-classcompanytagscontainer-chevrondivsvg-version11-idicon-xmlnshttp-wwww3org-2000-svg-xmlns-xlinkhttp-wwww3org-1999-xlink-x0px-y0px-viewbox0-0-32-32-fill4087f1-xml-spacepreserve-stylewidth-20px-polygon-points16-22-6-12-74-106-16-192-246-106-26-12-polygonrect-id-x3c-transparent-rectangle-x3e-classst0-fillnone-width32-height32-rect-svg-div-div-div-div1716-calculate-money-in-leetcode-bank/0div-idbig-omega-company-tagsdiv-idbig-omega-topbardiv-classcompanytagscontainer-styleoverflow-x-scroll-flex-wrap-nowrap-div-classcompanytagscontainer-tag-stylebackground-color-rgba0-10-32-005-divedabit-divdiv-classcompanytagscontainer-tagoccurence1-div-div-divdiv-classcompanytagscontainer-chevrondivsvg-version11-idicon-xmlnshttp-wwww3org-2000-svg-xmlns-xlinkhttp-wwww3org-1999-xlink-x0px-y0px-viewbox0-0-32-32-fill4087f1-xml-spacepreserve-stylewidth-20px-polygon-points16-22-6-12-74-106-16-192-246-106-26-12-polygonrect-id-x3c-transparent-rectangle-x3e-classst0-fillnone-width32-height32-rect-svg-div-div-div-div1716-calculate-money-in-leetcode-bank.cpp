class Solution {
public:
    int totalMoney(int n) {
        int sum1 = 0;
        int j = 0;
        int p = 2;
        int m = 1;
        for(int i = 1; i<=n; i++){
            if(i == (7*m) + 1){
                j = p;
                sum1 = sum1+(j);
                m++;
                p++;
            }
            else
                sum1 = sum1+(++j);
        }
        return sum1;
    }
};