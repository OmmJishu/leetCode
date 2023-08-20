class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        unordered_map<int,int> mp;
        
        int i = 0, j = 0;
        
        int sum = 0;
        for(; i<nums.size() && j<nums.size();){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]]++;
                sum += nums[i];
                mx = max(mx,sum);
                i++;
            }
            else{
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                sum -= nums[j];
                j++;
                mx = max(mx,sum);
            }
        }
        
        return mx;
    }
};