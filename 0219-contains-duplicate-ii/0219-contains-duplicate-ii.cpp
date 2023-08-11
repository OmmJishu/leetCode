class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]].first > 0) {
                if(abs(i - mp[nums[i]].second) <= k) {
                    return true;
                } 
                else {
                    mp[nums[i]].second = i;
                }
            } 
            else {
                mp[nums[i]].first++;
                mp[nums[i]].second = i;
            }
        }

        return false;
    }
};
