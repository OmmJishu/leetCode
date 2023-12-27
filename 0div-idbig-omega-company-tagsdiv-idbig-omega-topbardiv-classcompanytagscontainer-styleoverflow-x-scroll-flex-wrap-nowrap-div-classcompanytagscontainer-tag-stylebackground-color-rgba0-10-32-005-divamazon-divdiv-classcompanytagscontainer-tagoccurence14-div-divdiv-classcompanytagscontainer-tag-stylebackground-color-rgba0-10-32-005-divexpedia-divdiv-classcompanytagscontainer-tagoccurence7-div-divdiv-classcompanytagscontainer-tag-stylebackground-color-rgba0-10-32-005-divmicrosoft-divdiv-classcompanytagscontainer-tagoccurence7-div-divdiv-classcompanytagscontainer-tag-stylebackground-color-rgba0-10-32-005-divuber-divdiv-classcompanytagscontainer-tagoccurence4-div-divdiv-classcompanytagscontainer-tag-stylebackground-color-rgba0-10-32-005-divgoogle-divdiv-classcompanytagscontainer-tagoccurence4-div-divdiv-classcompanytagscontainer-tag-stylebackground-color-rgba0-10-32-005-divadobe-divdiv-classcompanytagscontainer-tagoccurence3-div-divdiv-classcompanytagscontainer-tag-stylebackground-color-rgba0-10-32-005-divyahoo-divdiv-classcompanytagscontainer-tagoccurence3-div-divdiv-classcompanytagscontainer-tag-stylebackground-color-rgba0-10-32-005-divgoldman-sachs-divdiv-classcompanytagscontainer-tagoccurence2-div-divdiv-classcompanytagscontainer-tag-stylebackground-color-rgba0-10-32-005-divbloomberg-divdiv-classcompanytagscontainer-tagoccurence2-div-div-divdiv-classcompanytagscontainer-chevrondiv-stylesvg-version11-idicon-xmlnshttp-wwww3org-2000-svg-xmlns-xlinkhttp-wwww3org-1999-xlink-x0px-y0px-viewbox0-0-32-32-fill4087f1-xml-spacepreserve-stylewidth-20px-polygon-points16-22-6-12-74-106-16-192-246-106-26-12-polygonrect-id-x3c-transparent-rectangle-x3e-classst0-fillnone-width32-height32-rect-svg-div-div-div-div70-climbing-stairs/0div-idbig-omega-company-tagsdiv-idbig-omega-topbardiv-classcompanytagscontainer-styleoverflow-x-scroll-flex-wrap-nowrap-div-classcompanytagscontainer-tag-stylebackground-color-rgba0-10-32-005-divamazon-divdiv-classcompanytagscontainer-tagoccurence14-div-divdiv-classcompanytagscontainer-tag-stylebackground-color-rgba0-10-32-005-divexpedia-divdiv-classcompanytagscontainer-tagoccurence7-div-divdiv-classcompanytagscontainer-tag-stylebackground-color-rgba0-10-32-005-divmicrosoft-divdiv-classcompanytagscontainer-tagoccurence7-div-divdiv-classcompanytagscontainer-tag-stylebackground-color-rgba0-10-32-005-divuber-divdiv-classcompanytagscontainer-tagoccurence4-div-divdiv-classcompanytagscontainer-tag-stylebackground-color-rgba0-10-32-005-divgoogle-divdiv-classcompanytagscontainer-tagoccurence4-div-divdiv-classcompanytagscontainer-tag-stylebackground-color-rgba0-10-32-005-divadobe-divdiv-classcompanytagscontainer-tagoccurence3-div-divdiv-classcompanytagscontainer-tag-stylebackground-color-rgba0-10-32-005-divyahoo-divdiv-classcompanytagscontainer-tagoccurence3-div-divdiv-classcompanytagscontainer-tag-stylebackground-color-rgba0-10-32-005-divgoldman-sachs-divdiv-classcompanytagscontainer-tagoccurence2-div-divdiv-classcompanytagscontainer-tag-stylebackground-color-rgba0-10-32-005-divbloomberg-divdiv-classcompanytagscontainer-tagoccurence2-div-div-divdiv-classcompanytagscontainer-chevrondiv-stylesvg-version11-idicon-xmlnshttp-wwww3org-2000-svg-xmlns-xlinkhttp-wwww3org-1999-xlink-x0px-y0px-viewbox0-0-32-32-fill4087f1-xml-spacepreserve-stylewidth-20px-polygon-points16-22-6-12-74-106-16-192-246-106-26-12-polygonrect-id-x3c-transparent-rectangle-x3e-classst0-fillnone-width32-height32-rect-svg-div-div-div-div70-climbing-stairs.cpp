class Solution {
private:
    int f(int idx, vector<int> &dp){
        if(idx == 0 || idx == 1)
            return 1;
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int left = f(idx-1, dp); // take 1 steps   first complete this recursion then 
        int right = f(idx-2, dp);  // take 2 steps complete and return
        
        return dp[idx] = left + right;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        return f(n, dp);
    }
};