class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n,true); // At start assume all prime
        
        for(long long i = 2; i<n; i++){
            if(prime[i] == true){ // unmarked
                for(long long j = i*i; j<n; j = j+i)
                    prime[j] = false; // marked as Not prime
            }
        }
        
        int count = 0;
        for(int i = 2; i<n; i++)
            if(prime[i] == true)
                count++;
        
        return count;
    }
};