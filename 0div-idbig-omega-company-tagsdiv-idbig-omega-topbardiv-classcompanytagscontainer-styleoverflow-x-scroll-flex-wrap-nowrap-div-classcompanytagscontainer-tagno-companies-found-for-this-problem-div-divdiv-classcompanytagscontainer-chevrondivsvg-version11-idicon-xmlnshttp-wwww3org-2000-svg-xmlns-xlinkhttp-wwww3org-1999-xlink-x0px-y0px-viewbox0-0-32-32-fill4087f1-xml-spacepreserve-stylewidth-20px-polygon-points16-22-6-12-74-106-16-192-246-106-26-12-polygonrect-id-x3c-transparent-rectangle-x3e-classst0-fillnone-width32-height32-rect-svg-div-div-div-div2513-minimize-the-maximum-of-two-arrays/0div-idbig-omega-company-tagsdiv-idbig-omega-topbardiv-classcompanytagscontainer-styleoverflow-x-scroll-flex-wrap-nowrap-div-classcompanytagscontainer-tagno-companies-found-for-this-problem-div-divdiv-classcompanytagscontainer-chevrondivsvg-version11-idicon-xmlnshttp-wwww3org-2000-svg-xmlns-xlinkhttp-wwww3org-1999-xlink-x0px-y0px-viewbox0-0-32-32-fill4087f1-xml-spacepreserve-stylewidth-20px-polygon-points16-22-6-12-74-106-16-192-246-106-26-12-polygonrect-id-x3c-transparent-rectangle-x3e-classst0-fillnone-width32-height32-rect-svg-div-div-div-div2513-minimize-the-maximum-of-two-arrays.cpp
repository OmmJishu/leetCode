class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long lcmAB(int a, int b) {
        return ((long long)a * (long long)b) / gcd(a, b);
    }
    
public:
    int minimizeSet(int d1, int d2, int uC1, int uC2) {
        // finding smallest numbers divisible by two numbers
        long long lcm = lcmAB(d1,d2);
        long long start = 1, end = INT_MAX;
        int res = INT_MAX;
        
        while(start <= end){
            long long mid = (start + end)/2;
            
            long long inA = mid - (mid/d1);  // A contains numbers Not divisible by d1
            long long inB = mid - (mid/d2);  // B contains numbers Not divisible by d2
            
            long long onlyInOne = mid - mid/lcm; 
            
            if(inA>=uC1 && inB >= uC2 && onlyInOne >= uC1+uC2){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        
        return res;
    }
};

    
    /*
        lcm = 15  uc1 = 10  uc2 = 4   -> ans = 14
        
        d1 = 3  ->   can take : 1,2,4,5,7,8,10,11,13,14  = 10 ele        Not take : 3,6,9,12,15
        d2 = 5 ->    can take : 1,2,3,4,6,7,8,9,11,12,13,14  = 12 ele    Not take : 5,10,15
        
                common :  1,2,4,7,8,11,13,14  = 8 ele can only be in one array
    */