class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        vector<vector<int>> res;
        
        for(int i = 0; (i+2)<nums.size(); i+=3){
            if(nums[i+2]-nums[i] <= k){
                res.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else{
                return {};
            }
        }
        
        int n = res.size();
        if(n*3 == nums.size()){
            return res;
        }
        
        return {};
    }
};