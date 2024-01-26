class Solution {
private:
    vector<vector<int>> res;
    
    void solve(int idx, vector<int>& candidates, int target, vector<int> &curr){
        int n = candidates.size();
        if(idx >= n) return;
        
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target < 0) return;
        
        curr.push_back(candidates[idx]);
        solve(idx, candidates, target - candidates[idx], curr);
        
        curr.pop_back();
        solve(idx + 1, candidates, target, curr);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        int n = candidates.size();
        vector<int> curr;
        
        solve(0,candidates,target,curr);
        
        return res;
    }
};