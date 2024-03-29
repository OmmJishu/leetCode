class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        
        int cntMaxi = 0, i = 0, j = 0, n = nums.size();
        long long total = 0;
        
        while(j<n){
            if(nums[j] == maxi) 
                cntMaxi++;
            
            if(cntMaxi == k){
                while(i<=j && cntMaxi == k){
                    total += (n-j);
                    if(nums[i] == maxi) 
                        cntMaxi--;
                    i++;
                }
            }
            
           j++;
        }
        
        return total;
    }
};