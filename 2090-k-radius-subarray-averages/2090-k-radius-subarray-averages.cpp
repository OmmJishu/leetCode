class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n,-1);
        int length = 2*k+1;
        
        if(n < length)
            return res;
        
        vector<long long> sum(n+1,0);
        for(int i = 0; i<n; i++)
            sum[i+1] = sum[i] + nums[i];
        
        for(int i = k; i+k<n; i++){
            res[i] = (sum[i+k+1] - sum[i-k])/length;
        }
        
        return res;
    }
};