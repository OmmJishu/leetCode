class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        
        for(int i = 1; i<nums.size(); i++){
            int temp = nums[i];
            nums[i] = max(nums[i-1]+1, nums[i]);
            int changed = nums[i];
            
            count = count + (changed-temp);
        }
    
        return count;
    }
};