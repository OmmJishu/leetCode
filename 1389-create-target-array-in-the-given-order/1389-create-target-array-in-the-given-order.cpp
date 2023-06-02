class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        
        for(int i = 0; i<nums.size(); i++){
            int indx = index[i];
            target.insert(target.begin()+indx,nums[i]);
        }
        
        return target;
    }
};