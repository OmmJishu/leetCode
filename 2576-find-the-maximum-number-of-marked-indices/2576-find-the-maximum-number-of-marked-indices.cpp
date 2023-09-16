class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0, n = nums.size();
        int i = 0, j = n/2;
        
        while(i<n/2 && j<n){
            if(nums[i]*2 <= nums[j]){
                cnt += 2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return cnt;
    }
};