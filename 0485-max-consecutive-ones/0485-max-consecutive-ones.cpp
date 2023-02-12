class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, mx = 0;
        int n = nums.size();
        if((n == 1 && nums[0] == 0) || (n == 1 && nums[0] == 1))
            return nums[0];
        if(n == 2){
            if(nums[0] == 1)
                count++;
            if(nums[1] == 1)
                count++;
            return count;
        }
            
        for(int i = 0; i<n; i++){
            int temp = nums[i];
            while(nums[i] == temp && temp == 1){
                count++;
                i++;
                if(i == n)
                    break;
            }
            mx = max(mx,count);
            count = 0;
        }
        return mx;
    }
};