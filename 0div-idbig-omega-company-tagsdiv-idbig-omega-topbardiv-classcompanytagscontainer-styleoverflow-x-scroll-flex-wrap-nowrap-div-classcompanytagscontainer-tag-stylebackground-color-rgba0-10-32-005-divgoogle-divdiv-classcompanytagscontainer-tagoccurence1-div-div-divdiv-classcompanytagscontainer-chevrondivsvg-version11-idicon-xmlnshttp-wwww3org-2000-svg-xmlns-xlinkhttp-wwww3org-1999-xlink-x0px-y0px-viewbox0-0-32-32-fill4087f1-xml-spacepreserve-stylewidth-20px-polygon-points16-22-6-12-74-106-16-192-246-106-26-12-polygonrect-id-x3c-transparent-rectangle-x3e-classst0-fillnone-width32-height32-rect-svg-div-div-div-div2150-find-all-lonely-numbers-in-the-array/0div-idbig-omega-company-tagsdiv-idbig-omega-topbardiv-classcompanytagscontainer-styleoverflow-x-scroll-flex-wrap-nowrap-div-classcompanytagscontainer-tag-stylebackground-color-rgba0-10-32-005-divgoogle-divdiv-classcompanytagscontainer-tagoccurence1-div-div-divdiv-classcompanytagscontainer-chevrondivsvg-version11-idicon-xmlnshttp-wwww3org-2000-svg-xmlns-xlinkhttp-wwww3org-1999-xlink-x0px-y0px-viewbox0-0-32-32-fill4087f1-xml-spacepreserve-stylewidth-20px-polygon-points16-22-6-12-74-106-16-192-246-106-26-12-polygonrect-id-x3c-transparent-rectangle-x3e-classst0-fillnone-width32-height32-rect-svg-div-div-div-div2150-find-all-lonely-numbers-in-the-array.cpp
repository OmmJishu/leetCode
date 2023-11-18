class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        vector<int> res;
        for(auto it : mp){
            if(it.second == 1){
                if(mp.count(it.first+1) == 0 && mp.count(it.first-1) == 0)
                    res.push_back(it.first);
            }
        }
        
        return res;
    }
};