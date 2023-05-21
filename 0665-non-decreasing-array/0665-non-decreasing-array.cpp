class Solution {
public:
bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int min_value = INT_MIN;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] <= nums[i + 1]){
                min_value = nums[i];
            }else{
                if(nums[i + 1] < min_value){
                    nums[i+1] = nums[i];
                }
                count -= 1;
            }
        }
        if(count < 0){
            return false;
        }else{
            return true;
        }
    }
};
    
    
// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         if(nums.size()>=3){
//         for(int i = 0; i<nums.size()-2; i++){
//             if(nums[i] == nums[i+2])
//                 return true;
//         }}
//         for(int i = 0; i<nums.size()-1; i++){
//             int temp = nums[i+1];
//             if(nums[i] > nums[i+1]){
//                 nums[i+1] = nums[i];
//                 if(check(nums))
//                     return true;
//                 else{
//                     nums[i+1] = temp;
//                     nums[i] = nums[i+1]-1;
//                     if(check(nums))
//                         return true;
//                 }
//                 break;
//             }
//         }
//         for(auto it : nums)
//             cout<<it<<" ";
//         return check(nums);
//     }
    
//     private:
//     bool check(vector<int>& nums){
//         for(int i = 0; i<nums.size()-1; i++){
//             if(nums[i]>nums[i+1])
//                 return false;
//         }
//         return true;
//     }
// };