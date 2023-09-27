class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        int idx1 = -1;
        for(int i = nums.size()-1; i>=1; i--){
            if(nums[i-1] < nums[i]){
                idx1 = i-1;
                break;
            }
        }
        if(idx1==-1){
            reverse(nums.begin(),nums.end());
        }
        else{

            int idx2 = -1;
            for(int i = nums.size()-1; i>idx1; i--){
                if(nums[i] > nums[idx1]){
                    idx2 = i;
                    break;
                }
            }

            int a = nums[idx1];
            nums[idx1] = nums[idx2];
            nums[idx2] = a;

            reverse(nums.begin()+idx1+1,nums.end());
        }
    }
};