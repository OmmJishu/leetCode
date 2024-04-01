class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long total = 1;
        
        int j = 0, i = 0, prev = nums[0], curr;
        
        for(int i = 1; i<nums.size(); i++){
            curr = nums[i];
            if(prev != curr){
                total += (i-j+1);
                prev = curr;
            }
            else{
                total += 1;
                prev = curr;
                j = i;
            }
        }
        
        return total;
    }
};