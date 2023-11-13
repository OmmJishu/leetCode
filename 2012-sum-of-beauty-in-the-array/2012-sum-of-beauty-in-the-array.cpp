class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMin(n,0);
        
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,nums[i]);
            prefixMax[i] = maxi;
        }
        
        int mini = INT_MAX;
        for(int i = n-1; i>=0; i--){
            mini = min(mini,nums[i]);
            suffixMin[i] = mini;
        }
        
        int sum = 0;
        for(int i = 1; i<n-1; i++){
            if(prefixMax[i-1] < nums[i] && nums[i] < suffixMin[i+1]){
                sum += 2;
            }
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]){
                sum += 1;
            }
        }
        
        return sum;
    }
};