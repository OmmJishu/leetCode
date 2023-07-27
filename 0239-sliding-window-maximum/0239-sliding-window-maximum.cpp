class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> mp;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        res.push_back(mp.rbegin()->first);

        for (int i = 1; i + k <= nums.size(); i++) {
            mp[nums[i - 1]]--;
            if (mp[nums[i - 1]] == 0) {
                mp.erase(nums[i - 1]);
            }
            
            mp[nums[i + k - 1]]++;
            res.push_back(mp.rbegin()->first);
        }

        return res;
    }
};