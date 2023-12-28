class Solution {
private:
    int fn(int idx, vector<int> &dp, vector<int> cost){
        int n = cost.size();
        if(idx == n-1)
            return cost[n-1];
        
        if(dp[idx] != -1) 
            return dp[idx];
        
        int left = fn(idx+1, dp, cost) ;
        int right = fn(idx+2, dp, cost) ;
        
        return dp[idx] = min(left,right) + cost[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2){
            return min(cost[0],cost[1]);
        }
        
        vector<int> dp(n+1,-1);
        dp[n] = 0;
        
        fn(0, dp, cost);
        return min(dp[0],dp[1]);
    }
};