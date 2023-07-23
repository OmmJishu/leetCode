class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        
        int n = nums.size();
        int sum = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int temp = nums[i] + nums[j] + nums[k];
                
                if(temp == target)
                    return target;
                
                if(abs(temp-target) < abs(sum-target))
                    sum = temp;
                
                else if(temp < target)
                    j++;
                
                else if(temp > target)
                    k--;
            }
        }
        
        return sum;
    }
};