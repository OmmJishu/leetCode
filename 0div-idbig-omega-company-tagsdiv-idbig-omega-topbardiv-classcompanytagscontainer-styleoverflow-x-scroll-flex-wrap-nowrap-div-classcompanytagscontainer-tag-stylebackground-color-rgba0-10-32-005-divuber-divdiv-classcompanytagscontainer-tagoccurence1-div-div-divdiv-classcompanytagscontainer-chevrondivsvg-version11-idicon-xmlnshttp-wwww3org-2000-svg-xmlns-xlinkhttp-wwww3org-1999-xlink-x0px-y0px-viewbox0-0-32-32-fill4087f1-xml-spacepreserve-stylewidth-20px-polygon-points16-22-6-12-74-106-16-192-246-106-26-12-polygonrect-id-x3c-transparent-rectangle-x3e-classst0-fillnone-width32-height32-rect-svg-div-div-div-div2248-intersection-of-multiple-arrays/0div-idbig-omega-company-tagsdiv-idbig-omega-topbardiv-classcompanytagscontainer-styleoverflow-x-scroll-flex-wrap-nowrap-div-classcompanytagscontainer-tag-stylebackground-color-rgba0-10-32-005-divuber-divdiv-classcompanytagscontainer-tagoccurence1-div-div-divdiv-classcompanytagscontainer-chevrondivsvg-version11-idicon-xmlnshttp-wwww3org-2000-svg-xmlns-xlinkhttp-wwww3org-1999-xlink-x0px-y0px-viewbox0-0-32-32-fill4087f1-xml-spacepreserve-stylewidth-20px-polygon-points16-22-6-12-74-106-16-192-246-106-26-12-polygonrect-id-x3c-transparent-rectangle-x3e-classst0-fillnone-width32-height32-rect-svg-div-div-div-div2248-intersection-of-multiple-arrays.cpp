class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            for(auto ele : it){
                mp[ele]++;
            }
        }
        vector<int> res;
        int maxi = INT_MIN;
        for(auto it : mp)
            maxi = max(maxi,it.second);
        
        if(maxi < nums.size())
            return {};
        
        for(auto it : mp)
            if(it.second == maxi)
                res.push_back(it.first);
        sort(res.begin(),res.end());
            
        return res;
    }
};