class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int j = 0;
        int n = nums.size();
        long sum = 0;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            while(sum >= target){
                mini = min(mini, i-j+1);
                sum -= nums[j++];
            }
        }
        if(mini == INT_MAX)
            return 0;
        return mini;
    }
};