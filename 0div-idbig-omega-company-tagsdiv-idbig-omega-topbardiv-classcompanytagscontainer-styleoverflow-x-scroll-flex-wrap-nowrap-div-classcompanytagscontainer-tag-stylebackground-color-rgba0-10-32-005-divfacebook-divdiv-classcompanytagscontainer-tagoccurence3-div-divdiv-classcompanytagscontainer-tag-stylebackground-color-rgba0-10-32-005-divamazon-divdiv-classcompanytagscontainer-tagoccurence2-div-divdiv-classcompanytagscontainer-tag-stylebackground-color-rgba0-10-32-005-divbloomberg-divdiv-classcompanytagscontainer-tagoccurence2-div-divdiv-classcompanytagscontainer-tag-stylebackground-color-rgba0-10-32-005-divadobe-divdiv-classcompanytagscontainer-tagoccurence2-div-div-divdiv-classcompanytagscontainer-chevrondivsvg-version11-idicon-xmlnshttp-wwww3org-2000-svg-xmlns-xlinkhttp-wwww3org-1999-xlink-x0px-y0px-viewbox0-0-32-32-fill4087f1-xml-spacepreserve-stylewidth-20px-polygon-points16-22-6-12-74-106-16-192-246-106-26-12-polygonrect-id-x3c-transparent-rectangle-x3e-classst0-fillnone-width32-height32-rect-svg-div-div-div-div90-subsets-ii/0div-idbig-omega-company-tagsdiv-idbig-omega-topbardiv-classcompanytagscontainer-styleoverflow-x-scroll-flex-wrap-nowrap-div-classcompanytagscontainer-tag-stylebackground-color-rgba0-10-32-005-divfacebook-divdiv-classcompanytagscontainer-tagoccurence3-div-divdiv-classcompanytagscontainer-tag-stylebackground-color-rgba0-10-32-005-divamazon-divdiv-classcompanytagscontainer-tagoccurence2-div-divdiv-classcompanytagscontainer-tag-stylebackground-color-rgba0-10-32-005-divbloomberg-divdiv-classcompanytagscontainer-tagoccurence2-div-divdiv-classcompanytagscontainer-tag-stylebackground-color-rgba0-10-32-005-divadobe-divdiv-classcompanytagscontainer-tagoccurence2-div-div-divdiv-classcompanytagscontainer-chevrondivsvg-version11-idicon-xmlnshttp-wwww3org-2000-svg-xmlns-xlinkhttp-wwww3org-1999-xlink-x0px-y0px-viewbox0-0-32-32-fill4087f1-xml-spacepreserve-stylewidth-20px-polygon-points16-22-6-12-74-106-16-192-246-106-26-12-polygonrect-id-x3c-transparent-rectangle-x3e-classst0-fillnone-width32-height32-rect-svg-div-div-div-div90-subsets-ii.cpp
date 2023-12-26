class Solution {
private:
    vector<vector<int>> res;
    set<vector<int>> st;
    
    void combinations(int idx, vector<int>& nums, vector<int> &curr){
        int n = nums.size();
        if(idx >= n){
            st.insert(curr);
            return;
        }
        
        int i = idx;
        for(i = idx; i<n; i++){
            if(i > idx && nums[i] == nums[i-1])
                continue;
            else
                break;
        }
        
        curr.push_back(nums[i]);
        combinations(i+1, nums, curr);
            
        // After every returning remember to pop_back
        curr.pop_back();
        combinations(i+1, nums, curr);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> curr;
        combinations(0, nums, curr);
        for(auto it : st) 
            res.push_back(it);
        
        return res;
    }
};