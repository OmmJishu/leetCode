class Solution {
private:
    int fun(int idx, vector<int> &dp){
        if(idx == 0) 
            return dp[idx] = 2;  // edge case
        if(idx == 1) 
            return dp[idx] =  3;  // edge case
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int take = fun(idx-2,dp)%1000000007;
        int notTake = fun(idx-1,dp)%1000000007;
        
        return dp[idx] = (take + notTake)%1000000007;
    }
    
public:
    int countHousePlacements(int n) {
        vector<int> dp(n+1,-1);
        
        long long ways = fun(n-1,dp);
        
        return (ways*ways)%1000000007;
    }
};