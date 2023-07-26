class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        unsigned long long ans = 0;
        
        for(int i = 0; i<nums.size(); i++){
            int temp = nums[i];
            int a = 0;
            while(temp){
                a = a*10 + temp%10;
                temp /= 10;
            }
            
            if(mp.find(nums[i]-a) == mp.end())
                mp[nums[i]-a]++;
            else{
                ans += mp[nums[i]-a];
                mp[nums[i]-a]++;
            }
        }
        
        return ans%1000000007;
    }
};