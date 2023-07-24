class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        else{
            double y = myPow(x, n/2);
            if(n % 2 < 0){
                return y * y / x;
            }
            else if(n % 2 > 0){
                return y * y * x;
            }
            else{
                return y * y;
            }  
        }
    }
};