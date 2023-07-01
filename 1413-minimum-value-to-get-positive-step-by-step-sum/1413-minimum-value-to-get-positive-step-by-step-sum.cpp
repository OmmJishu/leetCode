class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int sum = 1, startVal = 1;
        
        for(int j = 0; j<n;){
            sum += nums[j];
            if(sum < 1){
                startVal++;
                sum = startVal;
                j = 0;
            }
            else{
                j++;
            }
        }
        
        return startVal;
    }
};