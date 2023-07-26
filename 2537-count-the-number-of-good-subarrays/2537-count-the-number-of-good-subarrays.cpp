#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll ans = 0, count = 0;
        int i = 0, j = 0, n = nums.size();
        unordered_map<ll,ll> mp;
        
        for(j = 0; j<n; j++){
            mp[nums[j]]++;
            if(mp[nums[j]] > 1){
                count += mp[nums[j]] - 1;
            }
            
            while(i < j && count >= k){
                ans += n-j;
                mp[nums[i]]--;
                if(mp[nums[i]] >= 1){
                    count -= mp[nums[i]];
                }
                i++;
            }
        }
        
        return ans;
    }
};