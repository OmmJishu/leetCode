using ll = long long;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<ll,int>> dp(n);
        int ans = 0;
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                ll diff = (ll)nums[i] - (ll)nums[j];
                
                if(diff<=INT_MIN || diff>=INT_MAX)
                    continue;
                
                int curr = 0;
                if(dp[j].count(diff) > 0){
                    curr = dp[j][diff];
                }
                
                ans += curr;
                dp[i][diff] += curr+1;
            }
        }
        
        return ans;
    }
};