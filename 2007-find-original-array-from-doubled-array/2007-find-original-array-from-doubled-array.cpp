class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) 
            return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mp;
        vector<int> res;
        
        for(auto it : changed)
            mp[it]++;
        
        for(int i = 0; i<changed.size(); i++){
            if(mp[changed[i]] == 0)
                continue;
            if(mp[2*changed[i]] == 0)
                return {};
            else{
                res.push_back(changed[i]);
                mp[changed[i]]--;
                mp[2*changed[i]]--;
            }
        }
        
        return res;
    }
};