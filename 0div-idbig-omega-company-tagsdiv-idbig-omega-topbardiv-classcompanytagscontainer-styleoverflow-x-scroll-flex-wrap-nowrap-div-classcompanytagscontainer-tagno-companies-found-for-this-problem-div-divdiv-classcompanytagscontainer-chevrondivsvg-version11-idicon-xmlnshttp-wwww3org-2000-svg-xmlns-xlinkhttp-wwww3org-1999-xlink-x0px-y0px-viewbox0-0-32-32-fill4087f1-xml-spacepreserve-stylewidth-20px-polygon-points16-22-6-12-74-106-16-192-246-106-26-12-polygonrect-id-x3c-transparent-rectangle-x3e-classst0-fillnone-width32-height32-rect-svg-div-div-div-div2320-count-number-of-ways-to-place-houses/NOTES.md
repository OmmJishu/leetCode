class Solution {
private:
int fun(int idx, int n, vector<int> &dp){
if(idx == 0){
return 1;
}
if(idx<0)
return 0;
if(dp[idx] != -1){
return dp[idx];
}
int take = (1 + fun(idx-2,n,dp))%1000000007;
int notTake = (fun(idx-1,n,dp))%1000000007;
return dp[idx] = (take + notTake)%1000000007;
}
public:
int countHousePlacements(int n) {
vector<int> dp(n+1,-1);
int ans = 0;
int ways = fun(n-1,n,dp);
ans += ways;
return ans;
}
};