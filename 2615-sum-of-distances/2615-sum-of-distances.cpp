class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size());
        unordered_map<int, long long> sumLeft, countLeft;
        
        for(int i = 0; i<nums.size(); i++){
            res[i] = countLeft[nums[i]]*i - sumLeft[nums[i]];
            sumLeft[nums[i]] += i;
            countLeft[nums[i]]++;
        }
        
        unordered_map<int, long long> sumRight, countRight;
        
        for(int i = nums.size()-1; i>=0; i--){
            res[i] += (sumRight[nums[i]] - countRight[nums[i]]*i);
            sumRight[nums[i]] += i;
            countRight[nums[i]]++;
        }
        
        return res;
    }
};