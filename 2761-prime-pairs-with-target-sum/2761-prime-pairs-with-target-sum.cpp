class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;
        unordered_map<int,int> mp; // Make access fast
        
        primeSeive(n,mp); // Function call
        
        
        vector<int> prime;
        for(auto it : mp)
            prime.push_back(it.first);
        sort(prime.begin(),prime.end());  // To get res in sorted form
    
        
        for(int i = 0; i<prime.size(); i++){
            int req = n - prime[i]; // find if req exists in map and mp[req] > 0
            
            if(mp.find(req) != mp.end() && mp[req] > 0){
                res.push_back({prime[i],req});
                mp[prime[i]]--; // Make frequency of grouped prime[i] = 0
            }
        }
        
        return res;
    }
    
private:
    // sieve of eratosthenes
    void primeSeive(int n, unordered_map<int,int>& mp){
        vector<int> temp(n+1,0);
        
        for (long long i = 2; i <= n; i++)
            if (temp[i] == 0)
                for (long long j = i * i; j <= n; j = j + i)
                    temp[j] = 1;
           
        for (int i = 2; i <= n; i++)
            if (temp[i] == 0)
                mp[i]++;
    }
};