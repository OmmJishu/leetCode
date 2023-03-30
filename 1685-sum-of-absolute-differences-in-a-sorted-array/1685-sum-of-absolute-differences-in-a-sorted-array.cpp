class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        long long prevSum = 0;
        long long postSum = accumulate(nums.begin(),nums.end(),0);
        long long total = postSum;
        
        for(int i = 0; i<nums.size(); i++){
            postSum -= (prevSum + nums[i]);
            result[i] = (nums[i]*i - (prevSum)) + ((postSum) - nums[i]*(nums.size()-i-1));
            prevSum += nums[i];
            postSum = total;
        }
        return result;
    }
};