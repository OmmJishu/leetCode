class Solution {
private:
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(idx == n-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int k = idx+nums[idx];
        int mini = 1e9;
        for(int i = idx+1; i<=min(k,n-1); i++){
            int curr = 1 + solve(i,nums,dp);
            mini = min(mini,curr);
        }
        
        return dp[idx] = mini; 
    }
    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        return solve(0,nums,dp);
    }
};