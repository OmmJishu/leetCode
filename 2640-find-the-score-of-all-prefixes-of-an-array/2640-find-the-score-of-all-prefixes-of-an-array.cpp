class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res(nums.size());
        vector<long long> conver(nums.size());
        
        cout<<nums.size();
        
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
            conver[i] = nums[i] + maxi;
        }
        res[0] = conver[0];
        for(int i = 1; i<conver.size(); i++){
            res[i] = conver[i] + res[i-1];
        }
        return res;
    }
};