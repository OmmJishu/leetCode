class Solution {
private:
    int fun(int size, int idx, vector<vector<int>> &dp){
        if(size == 0) return 1;
        if(idx >= 5) return 0;
        
        if(dp[size][idx] != -1) return dp[size][idx];
        
        return dp[size][idx] = fun(size - 1, idx, dp) + fun(size, idx + 1, dp);
    }
    
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        
        return fun(n,0,dp);
    }
};