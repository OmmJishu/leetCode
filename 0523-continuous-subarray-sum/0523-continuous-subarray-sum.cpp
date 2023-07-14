class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        long long sum = 0;
        map<long long, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i<n; i++){
            sum += nums[i];
    
            if(k!=0)
                sum = sum%k;
            
            
            // if two runningSum mod k have the same values, then when they are subtracted, they are bound to be multiples of k   
            // eg mp<5,1> present due to sum = 11 ans 11%6 = 5 at index i = 1. Now sum = 35 and 35%6 == 5 at i  = 4 (let say) now element 5 occur already in mp    so   35 - 11 = 24 is sum of subarray from [i=1+1,i=4]
            
            if(mp.find(sum) != mp.end() ){
                int length = i - mp[sum];
                if(length >= 2){
                    return true;
                }
            }
            else
                mp[sum] = i;
        }
        
        return false;
    }
};