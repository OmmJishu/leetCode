class Solution {
public:
    int countElements(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums.size(); j++){
                if(nums[j] > nums[i]){
                    for(int k = 0; k<nums.size(); k++){
                        if(nums[k] < nums[i]){
                            count++;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return count;
    }
};