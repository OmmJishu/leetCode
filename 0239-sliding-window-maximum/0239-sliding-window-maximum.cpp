class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> freqMap;

        for (int i = 0; i < k; i++) {
            freqMap[nums[i]]++;
        }

        res.push_back(freqMap.rbegin()->first);

        for (int i = 1; i + k <= nums.size(); i++) {
            freqMap[nums[i - 1]]--;
            if (freqMap[nums[i - 1]] == 0) {
                freqMap.erase(nums[i - 1]);
            }
            
            freqMap[nums[i + k - 1]]++;
            res.push_back(freqMap.rbegin()->first);
        }

        return res;
    }
};