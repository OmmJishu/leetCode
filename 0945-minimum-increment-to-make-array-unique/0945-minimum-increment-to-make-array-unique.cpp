class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        long long count=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                count++;
                nums[i] = nums[i]+1;
            }
            else if(nums[i-1]>nums[i]){
                count += abs(nums[i]-nums[i-1])+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return count;
    }
};