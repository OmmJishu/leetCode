class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        long long sum = 0;
        map<long long, int> mp;
        mp[0] = 1;
        
        for(int i = 0; i<n; i++){
            sum += nums[i];
    
            int rem = sum - k;
            
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            
            mp[sum]++;  // mp[rem] = 3, it means there are 3 subarrays found so far whose cumulative sum is rem.
        }
        
        return count;
    }
};