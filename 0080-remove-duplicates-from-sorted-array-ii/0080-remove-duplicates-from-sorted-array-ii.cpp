class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        
        for(int i = 0; i<n; i++){
            int count = 1;
            
            while((i+1) < n && nums[i] == nums[i+1]){
                i++;
                count++;
            }
                
            for (int p = 0; p<min(2,count); p++){
                nums[k] = nums[i];
                k+=1;
            }
        }
        
        return k;
    }
};