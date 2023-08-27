class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(k-nums[i]) != mp.end() && mp[k-nums[i]] > 0){
                count++;
                if(mp[k-nums[i]] == 1)
                    mp.erase(k-nums[i]);
                else
                    mp[k-nums[i]]--;
                continue;
            }
            mp[nums[i]]++;
        }
        
        return count;
    }
};