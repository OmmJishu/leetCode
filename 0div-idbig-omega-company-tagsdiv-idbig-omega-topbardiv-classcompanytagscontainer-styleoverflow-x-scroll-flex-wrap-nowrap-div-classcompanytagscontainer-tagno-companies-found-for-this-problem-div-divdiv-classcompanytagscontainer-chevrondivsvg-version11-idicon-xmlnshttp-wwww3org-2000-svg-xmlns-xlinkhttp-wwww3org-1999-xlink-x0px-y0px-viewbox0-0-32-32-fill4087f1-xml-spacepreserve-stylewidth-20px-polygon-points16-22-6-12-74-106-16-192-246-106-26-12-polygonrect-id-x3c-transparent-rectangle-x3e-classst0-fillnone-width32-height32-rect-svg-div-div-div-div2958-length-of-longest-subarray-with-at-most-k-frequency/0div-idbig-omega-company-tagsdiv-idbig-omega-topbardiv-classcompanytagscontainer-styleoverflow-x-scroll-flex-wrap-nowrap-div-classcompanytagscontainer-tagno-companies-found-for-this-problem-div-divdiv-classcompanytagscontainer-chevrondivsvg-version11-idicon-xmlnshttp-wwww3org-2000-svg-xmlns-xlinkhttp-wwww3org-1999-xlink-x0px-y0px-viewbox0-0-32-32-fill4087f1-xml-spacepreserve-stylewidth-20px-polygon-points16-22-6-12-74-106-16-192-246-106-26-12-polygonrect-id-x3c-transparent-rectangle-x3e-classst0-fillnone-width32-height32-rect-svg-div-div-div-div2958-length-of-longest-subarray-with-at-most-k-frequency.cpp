class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0, j = 0, n = nums.size();
        int maxi = 0;
        
        while(i<n && j<n){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
    }
};