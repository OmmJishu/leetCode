class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>> dp(n);
        int ans = 0;
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i] - nums[j];
                
                if(diff<=INT_MIN || diff>=INT_MAX)
                    continue;
                
                int curr = 0;
                if(dp[j].count(diff) > 0 && j+1 == i){
                    curr = dp[j][diff];
                }
                
                ans += curr;
                if(j+1 == i)
                    dp[i][diff] += curr+1;
            }
        }
        
        return ans;
    }
};