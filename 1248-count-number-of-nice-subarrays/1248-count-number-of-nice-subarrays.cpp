class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]%2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }
 
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        // The reason behind this initialization is to handle the case where there is no element before the start of the subarray. Since the subarray starts from the beginning, if its sum is equal to k (the required number of odd elements), then we need to count it in the final result.
        // eg :-   nums = [1]  and   k = 1

        
        for(int i = 0; i<n; i++){
            sum += nums[i];
            int rem = sum - k;
            
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            
            mp[sum]++;  // mp[rem] = 4, (rem= 0 say) it means there are 4 subarrays found so far who fot for k
        }
        
        return count;
    }
};