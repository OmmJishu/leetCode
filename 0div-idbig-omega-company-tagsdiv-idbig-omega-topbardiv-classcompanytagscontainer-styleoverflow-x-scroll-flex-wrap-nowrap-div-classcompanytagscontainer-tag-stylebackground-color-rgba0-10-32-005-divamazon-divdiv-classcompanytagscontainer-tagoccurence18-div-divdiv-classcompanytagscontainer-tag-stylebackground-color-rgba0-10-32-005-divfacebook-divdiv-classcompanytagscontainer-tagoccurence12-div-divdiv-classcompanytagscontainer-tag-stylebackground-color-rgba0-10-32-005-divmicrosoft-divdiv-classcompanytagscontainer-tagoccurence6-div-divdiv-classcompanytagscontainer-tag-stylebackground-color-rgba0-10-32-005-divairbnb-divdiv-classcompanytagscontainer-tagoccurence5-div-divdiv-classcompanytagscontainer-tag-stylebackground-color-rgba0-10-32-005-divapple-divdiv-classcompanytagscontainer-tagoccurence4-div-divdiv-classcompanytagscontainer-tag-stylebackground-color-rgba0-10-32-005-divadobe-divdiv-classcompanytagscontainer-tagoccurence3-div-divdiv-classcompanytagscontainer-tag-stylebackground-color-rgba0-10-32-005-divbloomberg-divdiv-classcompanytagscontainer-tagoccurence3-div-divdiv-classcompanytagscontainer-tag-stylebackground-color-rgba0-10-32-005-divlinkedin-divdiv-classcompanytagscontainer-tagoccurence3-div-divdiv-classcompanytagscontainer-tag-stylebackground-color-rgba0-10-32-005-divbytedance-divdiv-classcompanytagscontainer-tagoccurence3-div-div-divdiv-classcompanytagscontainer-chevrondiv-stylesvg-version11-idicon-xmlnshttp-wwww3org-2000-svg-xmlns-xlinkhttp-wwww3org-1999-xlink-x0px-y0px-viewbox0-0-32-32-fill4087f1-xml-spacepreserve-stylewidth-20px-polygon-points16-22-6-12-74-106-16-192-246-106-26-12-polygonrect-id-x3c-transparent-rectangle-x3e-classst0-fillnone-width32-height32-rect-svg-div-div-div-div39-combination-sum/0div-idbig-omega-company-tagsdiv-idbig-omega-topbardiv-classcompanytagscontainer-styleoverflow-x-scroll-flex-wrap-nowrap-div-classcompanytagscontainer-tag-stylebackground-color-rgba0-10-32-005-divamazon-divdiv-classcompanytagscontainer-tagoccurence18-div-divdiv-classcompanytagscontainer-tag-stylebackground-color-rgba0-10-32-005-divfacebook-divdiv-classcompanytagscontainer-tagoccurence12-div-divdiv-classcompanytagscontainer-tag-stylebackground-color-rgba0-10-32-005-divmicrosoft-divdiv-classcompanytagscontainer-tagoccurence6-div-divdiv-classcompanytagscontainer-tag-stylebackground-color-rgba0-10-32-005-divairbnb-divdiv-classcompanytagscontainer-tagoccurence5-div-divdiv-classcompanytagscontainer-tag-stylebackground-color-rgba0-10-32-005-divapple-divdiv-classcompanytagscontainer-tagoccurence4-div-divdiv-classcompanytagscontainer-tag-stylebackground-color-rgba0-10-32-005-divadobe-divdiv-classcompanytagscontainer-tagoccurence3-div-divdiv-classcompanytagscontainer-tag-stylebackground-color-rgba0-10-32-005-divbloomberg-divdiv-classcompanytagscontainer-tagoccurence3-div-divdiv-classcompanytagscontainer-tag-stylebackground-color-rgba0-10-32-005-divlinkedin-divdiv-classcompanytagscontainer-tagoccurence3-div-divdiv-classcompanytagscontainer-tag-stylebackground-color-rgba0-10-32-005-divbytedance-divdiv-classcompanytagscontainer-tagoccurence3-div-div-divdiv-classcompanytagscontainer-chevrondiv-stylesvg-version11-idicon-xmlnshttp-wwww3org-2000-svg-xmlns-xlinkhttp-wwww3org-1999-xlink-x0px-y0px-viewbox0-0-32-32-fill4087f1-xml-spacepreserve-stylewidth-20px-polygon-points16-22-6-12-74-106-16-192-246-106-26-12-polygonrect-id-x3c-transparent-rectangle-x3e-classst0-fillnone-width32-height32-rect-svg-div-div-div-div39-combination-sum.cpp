class Solution {
private:
    vector<vector<int>> res;
    set<vector<int>> st;
    
    void solve(int idx, vector<int>& candidates, int target, vector<int> &curr){
        int n = candidates.size();
        if(idx == n){
            if(target == 0){
                st.insert(curr);
                return;
            }
            return;
        }
        
        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);
            solve(idx,candidates,target - candidates[idx],curr);
            
            curr.pop_back();
        }
        
        solve(idx + 1,candidates,target,curr);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        vector<int> curr;
        solve(0,candidates,target,curr);
        
        for(auto it : st){
            res.push_back(it);
        }
        
        return res;
    }
};