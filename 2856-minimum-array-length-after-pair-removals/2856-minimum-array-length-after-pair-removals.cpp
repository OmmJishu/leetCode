class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int i = 0, n = nums.size(), j = n/2, cnt = 0;
        
        while(i<n/2 && j <n){
            if(nums[i] < nums[j]){
                cnt += 2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return n-cnt;
    }
};