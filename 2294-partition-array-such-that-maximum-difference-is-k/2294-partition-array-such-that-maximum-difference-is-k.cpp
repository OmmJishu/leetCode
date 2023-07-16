class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 1, j =0;
        
        for(int i = 0; i<nums.size();){
            if(nums[i] - nums[j] <= k){
                i++;
            }
            else if(nums[i] - nums[j] > k){
                count++;
                j = i;
                i++;
            }
        }
        
        return count;
    }
};