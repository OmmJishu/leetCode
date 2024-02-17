class Solution {
private:
    vector<int> power;
    int solve(int num, vector<int> &dp){
        if(num == 1)
            return 0;
        
        if(dp[num] != -1) return dp[num];
        
        if(num%2 == 0){
            return dp[num] = 1 + solve(num/2,dp);
        }
        
        return dp[num] = 1 + solve(num*3+1,dp);
    }
    
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(300000,-1);
        vector<pair<int,int>> store;
        
        for(int i = lo; i<=hi; i++){
            store.push_back({solve(i,dp),i});
        }
        sort(store.begin(),store.end());
    
        return store[k-1].second;
    }
};