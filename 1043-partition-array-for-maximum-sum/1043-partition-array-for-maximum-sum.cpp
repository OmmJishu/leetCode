class Solution {
private:
    int res = 0;
    
    int solve(int idx, vector<int>& arr, vector<int>& dp, int k){
        int n = arr.size();
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int currMaxi = 0, sum = 0;
        for(int j = idx; j<min(n,idx+k); j++){
            currMaxi = max(currMaxi,arr[j]);
            sum = currMaxi*(j-idx+1) + solve(j+1,arr,dp,k);
            res = max(res, sum);
        }
        
        return dp[idx] = res;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        
        // Memoization
        // int num = solve(0,arr,dp,k);
        // return num;
        
        
        // Tabulization
        
        dp[n] = 0;
        for(int idx = n-1; idx>=0; idx--){
            int currMaxi = 0;
            
            for(int j = idx; j<min(n,idx+k); j++){
                currMaxi = max(currMaxi,arr[j]);
                int sum = currMaxi*(j-idx+1) + solve(j+1,arr,dp,k);
                res = max(res, sum);
            }

            dp[idx] = res;
        }
        
        return dp[0];
    }
};