#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        ll sum = 0, ans = 0;
        
        for (int i = 0; i<k; i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        if(mp.size() == k)
            ans = max(ans,sum);
        
        for(int j = 1; j+k<=nums.size(); j++){
            mp[nums[j-1]]--;
            if (mp[nums[j-1]] == 0)
                mp.erase(nums[j - 1]);
            
            mp[nums[j+k-1]]++;
            
            sum -= nums[j-1];
            sum += nums[j+k-1];
            
            if(mp.size() == k) 
                ans = max(ans, sum);    
        }
        
        return ans;
    }
};