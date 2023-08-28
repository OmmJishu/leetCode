class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int i = 0 , lf = -1, ri = -1;
      
        for(; i<nums.size(); i++){
            if(nums[i] > right)
                lf = i;
            if(nums[i] >= left)
                ri = i;
            
            ans += ri-lf;
        }
       
        return ans;
    }
};