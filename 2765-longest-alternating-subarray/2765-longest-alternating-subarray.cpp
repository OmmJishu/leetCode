class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
       int n = nums.size();
       int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int prev = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] - nums[j-1] == prev) {
                    ans = max(ans, j - i + 1);
                } 
                else {
                    break;
                }
                prev = -prev;
            }
        }
        
        if(ans == 0)
            return -1;
        return ans;
    }
};