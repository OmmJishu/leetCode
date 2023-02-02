class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(),count = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 1; i<n; i++)
            if(nums[i]!=nums[i-1])
                count = count+i;
        return count;
    }
};