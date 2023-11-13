using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefixMax(n,0);
        vector<ll> suffixMax(n,0);
        
        ll maxi = -1;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,static_cast<ll>(nums[i]));
            prefixMax[i] = maxi;
        }
        
        maxi = -1;
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi,static_cast<ll>(nums[i]));
            suffixMax[i] = maxi;
        }
        
        ll ans = 0;
        for(int i = 1; i<n-1; i++){
            ans = max(ans, ((prefixMax[i-1] - nums[i]) * suffixMax[i+1]));
        }
        
        return ans;
    }
};