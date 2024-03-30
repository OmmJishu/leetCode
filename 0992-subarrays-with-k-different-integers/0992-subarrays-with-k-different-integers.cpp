class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
    
    int atMostK(vector<int> &nums,int k){
        int cnt = 0;
        unordered_map<int,int> mp;
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            while(mp.size() > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            cnt += (i-j+1);
        }
        
        return cnt;
    }
};