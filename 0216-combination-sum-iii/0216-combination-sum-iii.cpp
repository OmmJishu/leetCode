class Solution {
private:
    vector<vector<int>> res;
    
    void combinations(int idx, vector<int> &arr, int k, int target, vector<int> &curr){
        int n = arr.size();
        if(idx > n)
            return;
        
        if(k == 0){
            if(target == 0){
                res.push_back(curr);
            }
            return;
        }
        
        for(int i = idx; i < n; ++i){
            curr.push_back(arr[i]);
            combinations(i + 1, arr, k - 1, target - arr[i], curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> curr;
        
        combinations(0, arr, k, n, curr);
        
        return res;
    }
};