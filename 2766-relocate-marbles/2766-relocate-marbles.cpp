class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        
        for(int i = 0; i<moveFrom.size(); i++){
            mp.erase(moveFrom[i]);
            mp[moveTo[i]]++;
        }
        
        vector<int> res;
        for(auto it : mp)
            res.push_back(it.first);
        
        return res;
    }
};