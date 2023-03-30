class Solution {
public:
    bool check(int n){
        int num = n;
        int digit, rev = 0;
        do{
            digit = n % 10;
            rev = (rev * 10) + digit;
            n = n / 10;
        } while (n != 0);
        if (num == rev)
            return true;
        else
            return false;
    }
    bool sieve(int n){
        if(n==1)
            return false;
        for(long long i = 2; i*i <= n; i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if (n >= 9989900)
            return 100030001;
        for(int j = n; j<100000000; j++){
           if(sieve(j)){
               if(check(j)){
                    return j;
               }
           }
        }
        return 0;
    }
};