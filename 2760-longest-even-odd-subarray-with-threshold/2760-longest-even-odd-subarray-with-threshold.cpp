class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int count = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0 && nums[i] <= threshold){
                int c = 1;
                for(; i<nums.size()-1; i++){
                    if((nums[i]%2 != nums[i+1]%2)  && nums[i+1] <= threshold)
                        c++;
                    else 
                        break;
                }
                
                count = max(count,c);
            }
        }
        
        return count;
    }
};