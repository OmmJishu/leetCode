class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int idx1 = 0, idxN = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 1) idx1 = i;
            if(nums[i] == n) idxN = i;
        }
        
        return (idx1 < idxN) ? idx1 + (n-idxN-1) : idx1 + (n-idxN-1) - 1;
    }
};