class Solution {
private:
    vector<vector<int>> res;
    
    void printPermutation(vector<int>& nums, vector<int>& curr, unordered_map<int,int> mp){
        int n = nums.size();
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(mp[nums[i]] == 0){
                curr.push_back(nums[i]);
                mp[nums[i]] = 1;
                
                printPermutation( nums, curr, mp);
                
                // After every returning remember to pop_back and mark that element 0 in map 
                curr.pop_back();
                // cout<<nums[i]<<" ";
                mp[nums[i]] = 0;
            }
            // cout<<endl;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> curr;
        
        printPermutation(nums, curr, mp);
        
        return res;
    }
};