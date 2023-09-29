class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool first = true, second = true;
        for(int i = 0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                first = false;
                break;
            }
        }
                
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                second = false;
                break;
            }
        }
        
        if(!first && !second)
            return false;
            
        return true;
    }
};