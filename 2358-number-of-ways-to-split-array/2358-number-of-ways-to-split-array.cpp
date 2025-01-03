class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long lastSum = 0, firstSum = 0;
        for(auto it : nums) 
            lastSum += it;
        
        int count = 0;
        for(int i = 0; i<nums.size()-1; i++){
            firstSum += nums[i];
            lastSum -= nums[i];
                
            if(firstSum >= lastSum)
                count++;
        }
        
        return count;
    }
};