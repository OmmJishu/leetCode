class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {

       int count =0 ,n=nums.size();

       for(int i=0 ;i<n;i++){
           if(nums[i]%2==0 && nums[i]<=threshold){
             int c=1;
             for(;i<n-1;i++){
                 if(nums[i]%2 != nums[i+1]%2 && nums[i+1]<=threshold){
                     c++;
                 }
                 else {
                     break;
                 }
             }

             count=max(count,c);
           }
       } 
       return count;
    }
};