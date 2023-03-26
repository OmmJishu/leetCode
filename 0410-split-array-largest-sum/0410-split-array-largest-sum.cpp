class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = low;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    private:
        bool check(vector<int> nums,int k,int mid){
            int sum = 0, count = 1;
            for(int i = 0; i<nums.size(); i++){
                if(sum+nums[i]>mid){
                    sum = nums[i];
                    count++;
                    if(count>k) 
                        return false;
                }
                else
                    sum = sum + nums[i];
            }
            return true;
        }
};