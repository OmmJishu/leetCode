class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0,  product = 1;
        int i = 0, j = 0;
        
        while(j < n){
            product *= nums[j];
            
            while (i < n && product >= k)
                product /= nums[i++];
            
            if(product > 0)
                count += (j - i + 1);
            j++;
        }
        
        return count < 0 ? 0 : count;
    }
};