class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k) - atmostk(nums,k-1);
    }
    
private:
    int atmostk(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
    
        for (int j = 0, p = 0; p < nums.size(); p++) {
            mp[nums[p]]++;
            while (mp.size() > k) {
                mp[nums[j]]--;
                if (mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            ans += (p - j + 1);
        }
        
        return ans;
    }
};