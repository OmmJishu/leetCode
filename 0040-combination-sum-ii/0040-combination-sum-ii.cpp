class Solution {
private:
    vector<vector<int>> res;
    
    void combinations(int idx, vector<int>& candidates, vector<int> &curr, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
      
        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            if(target < candidates[i])
                break;
            
            curr.push_back(candidates[i]);
            combinations(i + 1, candidates, curr, target - candidates[i]);
            
            //after every returning
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        
        combinations(0,candidates,curr,target);
        
        return res;
    }
};