class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        unordered_map<int,int> mp;
        
        int sum = 0, i = 0;
        for(; i<nums.size(); i++){
            sum += nums[i];
            if(sum == goal)
                ans++;
            
            if(mp.find(sum - goal) != mp.end())
                ans += mp[sum - goal];
            
            mp[sum]++;
        }
        
        return ans;
    }
};