class Solution {
private:
    // for N-1 to 1
    int fun1(int idx, vector<int>& nums, vector<int>& dp){
        if(idx < 0)
            return 0;
        if(idx == 0){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int pick = nums[idx] + fun1(idx-2, nums, dp);
        int notPick = fun1(idx-1, nums, dp);
        
        return dp[idx] = max(pick,notPick);
    }
    
    // For N-2  to  0
    int fun2(int idx, vector<int>& nums, vector<int>& dp){
        if(idx < 0)
            return 0;
        if(idx == 0){
            return nums[idx];
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int pick = nums[idx] + fun2(idx-2, nums, dp);
        int notPick = fun2(idx-1, nums, dp);
        
        return dp[idx] = max(pick,notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n+1,-1);
        
        int first = fun1(n-1,nums,dp);  // N-1 to 1
        
        for(int i = 0; i<= n; i++) dp[i] = -1;
        int second = fun2(n-2,nums,dp);  // N-2 to 0
        
        return max(first,second);
    }
};