class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int i = 0, j = 0;
        int maxi = INT_MIN;
        
        while(i<n){
            if(nums[i] - nums[j] > 2*k)
                j++;
            else
                maxi = max(maxi,i-j+1);
            i++;
        }
        
        return maxi;
    }
};