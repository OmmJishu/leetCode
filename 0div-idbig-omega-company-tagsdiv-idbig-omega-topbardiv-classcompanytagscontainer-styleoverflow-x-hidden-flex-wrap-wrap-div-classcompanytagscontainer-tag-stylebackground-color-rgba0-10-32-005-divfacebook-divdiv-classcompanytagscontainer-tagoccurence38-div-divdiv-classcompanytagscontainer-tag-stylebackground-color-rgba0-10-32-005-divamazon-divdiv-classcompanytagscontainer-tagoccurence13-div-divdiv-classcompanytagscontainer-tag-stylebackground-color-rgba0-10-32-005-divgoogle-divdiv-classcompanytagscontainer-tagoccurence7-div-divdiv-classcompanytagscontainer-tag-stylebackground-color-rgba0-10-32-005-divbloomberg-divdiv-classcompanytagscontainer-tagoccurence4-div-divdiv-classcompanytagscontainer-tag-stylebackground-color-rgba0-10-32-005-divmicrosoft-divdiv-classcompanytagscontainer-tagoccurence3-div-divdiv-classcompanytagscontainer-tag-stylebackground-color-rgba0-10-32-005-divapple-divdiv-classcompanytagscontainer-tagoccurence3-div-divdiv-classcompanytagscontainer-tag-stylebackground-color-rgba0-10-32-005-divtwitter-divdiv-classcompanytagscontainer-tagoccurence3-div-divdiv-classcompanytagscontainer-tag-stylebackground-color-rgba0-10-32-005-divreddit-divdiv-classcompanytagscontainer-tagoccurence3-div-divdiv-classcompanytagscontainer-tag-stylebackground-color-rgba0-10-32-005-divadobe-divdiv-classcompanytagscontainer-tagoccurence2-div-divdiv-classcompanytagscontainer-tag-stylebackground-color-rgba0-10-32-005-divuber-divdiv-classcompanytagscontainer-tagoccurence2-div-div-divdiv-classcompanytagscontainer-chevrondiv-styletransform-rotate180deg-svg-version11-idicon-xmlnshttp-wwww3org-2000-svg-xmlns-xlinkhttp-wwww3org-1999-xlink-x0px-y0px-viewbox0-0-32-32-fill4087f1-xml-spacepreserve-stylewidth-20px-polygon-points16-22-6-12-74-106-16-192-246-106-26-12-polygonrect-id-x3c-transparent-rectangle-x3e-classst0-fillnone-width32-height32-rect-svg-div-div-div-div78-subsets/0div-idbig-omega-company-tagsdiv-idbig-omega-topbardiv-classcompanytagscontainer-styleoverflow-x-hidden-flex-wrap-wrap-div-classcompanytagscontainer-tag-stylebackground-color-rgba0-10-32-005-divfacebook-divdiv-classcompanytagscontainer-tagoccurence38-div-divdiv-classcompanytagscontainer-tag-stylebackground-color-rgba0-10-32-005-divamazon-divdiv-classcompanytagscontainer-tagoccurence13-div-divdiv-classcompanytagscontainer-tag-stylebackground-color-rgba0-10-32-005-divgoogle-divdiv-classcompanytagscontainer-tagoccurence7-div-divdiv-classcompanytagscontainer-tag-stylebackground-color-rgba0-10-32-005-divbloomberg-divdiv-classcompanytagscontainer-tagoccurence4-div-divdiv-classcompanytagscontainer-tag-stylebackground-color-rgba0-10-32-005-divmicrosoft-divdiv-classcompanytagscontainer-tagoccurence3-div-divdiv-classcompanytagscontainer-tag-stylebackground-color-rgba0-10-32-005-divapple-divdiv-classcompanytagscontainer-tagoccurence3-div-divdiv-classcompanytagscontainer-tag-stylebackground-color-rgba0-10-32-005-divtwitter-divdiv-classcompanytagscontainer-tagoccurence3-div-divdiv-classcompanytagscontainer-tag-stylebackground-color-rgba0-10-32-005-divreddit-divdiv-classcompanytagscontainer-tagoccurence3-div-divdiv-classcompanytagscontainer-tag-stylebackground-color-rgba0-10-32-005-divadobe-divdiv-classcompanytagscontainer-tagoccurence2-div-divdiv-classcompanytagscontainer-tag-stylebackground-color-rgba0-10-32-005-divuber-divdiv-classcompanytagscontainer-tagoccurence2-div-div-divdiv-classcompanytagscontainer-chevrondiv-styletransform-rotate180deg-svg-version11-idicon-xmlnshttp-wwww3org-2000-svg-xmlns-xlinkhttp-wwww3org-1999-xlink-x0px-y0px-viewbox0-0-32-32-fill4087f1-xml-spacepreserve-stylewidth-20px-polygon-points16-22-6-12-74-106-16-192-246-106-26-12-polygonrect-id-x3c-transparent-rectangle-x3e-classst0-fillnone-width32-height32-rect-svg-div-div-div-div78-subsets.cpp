class Solution {
private:
    vector<vector<int>> res;
    
    void combinations(int idx, vector<int>& nums, vector<int> &curr){
        int n = nums.size();
        
        if(idx >= n){
            res.push_back(curr);
            return;
        }
        
        curr.push_back(nums[idx]);
        combinations(idx + 1, nums, curr);
        
        curr.pop_back();
        combinations(idx + 1, nums, curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        combinations(0,nums,curr);
        
        return res;
    }
};