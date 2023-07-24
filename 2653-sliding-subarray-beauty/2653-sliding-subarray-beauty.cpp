class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> res;
        map<int, int> mp;
        
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        
        int cnt = 0;
        for (auto it : mp) {
            if (it.first < 0) {
                cnt += it.second;
            }
            if (cnt >= x) {
                res.push_back(it.first);
                break;
            }
        }
        if (cnt < x)
            res.push_back(0);
            
        
        
        for (int i = 1; i + k <= nums.size(); i++) {
            if (mp[nums[i - 1]] == 1) {
                mp.erase(nums[i - 1]);
            } else if (mp[nums[i - 1]] > 1) {
                --mp[nums[i - 1]];
            }
            
            mp[nums[i + k - 1]]++;
            
            cnt = 0;
            for (auto it : mp) {
                if (it.first < 0) {
                    cnt += it.second;
                }
                if (cnt >= x) {
                    res.push_back(it.first);
                    break;
                }
            }
            if (cnt < x)
                res.push_back(0);

        }
        
        return res;
    }
};
