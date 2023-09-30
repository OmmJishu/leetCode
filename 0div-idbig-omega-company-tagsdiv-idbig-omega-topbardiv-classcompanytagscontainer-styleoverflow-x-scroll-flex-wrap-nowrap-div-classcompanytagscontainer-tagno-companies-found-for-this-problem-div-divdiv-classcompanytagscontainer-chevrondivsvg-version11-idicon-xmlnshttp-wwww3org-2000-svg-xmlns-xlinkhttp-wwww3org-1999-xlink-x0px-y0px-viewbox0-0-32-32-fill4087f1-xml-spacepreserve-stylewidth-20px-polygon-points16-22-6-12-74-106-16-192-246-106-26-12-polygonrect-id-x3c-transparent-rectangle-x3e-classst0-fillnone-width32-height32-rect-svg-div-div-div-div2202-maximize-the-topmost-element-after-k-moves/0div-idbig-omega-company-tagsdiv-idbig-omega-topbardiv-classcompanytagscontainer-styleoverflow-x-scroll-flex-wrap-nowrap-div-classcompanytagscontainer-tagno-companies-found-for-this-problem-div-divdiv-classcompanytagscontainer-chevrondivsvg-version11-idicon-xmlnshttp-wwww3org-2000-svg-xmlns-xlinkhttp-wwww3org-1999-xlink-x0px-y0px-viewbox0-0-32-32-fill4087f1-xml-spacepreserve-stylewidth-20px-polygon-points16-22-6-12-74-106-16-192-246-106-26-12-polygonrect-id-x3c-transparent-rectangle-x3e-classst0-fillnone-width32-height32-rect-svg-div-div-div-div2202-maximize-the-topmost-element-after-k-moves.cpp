class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0)
            return nums[0];
        if(k % 2 != 0 && nums.size() == 1)
            return -1;
        
        int maxi = -1;
        int x = k-1;
        int i = 0;
        for(i = 0; i<nums.size(); i++){
            if(x-- > 0)
                maxi = max(maxi,nums[i]);
            else
                break;
        }
        
        if(i+1 < nums.size())
            maxi = max(maxi,nums[i+1]);
        return maxi;
    }
};