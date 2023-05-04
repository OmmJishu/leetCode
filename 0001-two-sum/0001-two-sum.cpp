class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                int index1 = i;
                int index2 = mp[target - nums[i]];
                if(index1 != index2)
                    return {index1, index2};
            }   
            mp[nums[i]] = i;
        }
        return {};
    }
};