class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<long long,int> mp;
        long long sum = 0, maxi = INT_MIN;
        
        // First Window
        for(int i = 0; i<k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() >= m)
            maxi = max(maxi,sum);
        
        // Rest of the Windows
        int j = 0;
        for(int i=k ;i<nums.size() ;i++){
           sum += nums[i];
           sum -= nums[j];
           mp[nums[i]]++;
           mp[nums[j]]--;
           if(mp[nums[j]]==0) 
               mp.erase(nums[j]);
           if(mp.size()>=m)
               maxi = max(maxi,sum);
           j++;

       }
        
        return maxi == INT_MIN ? 0 : maxi;
    }
};