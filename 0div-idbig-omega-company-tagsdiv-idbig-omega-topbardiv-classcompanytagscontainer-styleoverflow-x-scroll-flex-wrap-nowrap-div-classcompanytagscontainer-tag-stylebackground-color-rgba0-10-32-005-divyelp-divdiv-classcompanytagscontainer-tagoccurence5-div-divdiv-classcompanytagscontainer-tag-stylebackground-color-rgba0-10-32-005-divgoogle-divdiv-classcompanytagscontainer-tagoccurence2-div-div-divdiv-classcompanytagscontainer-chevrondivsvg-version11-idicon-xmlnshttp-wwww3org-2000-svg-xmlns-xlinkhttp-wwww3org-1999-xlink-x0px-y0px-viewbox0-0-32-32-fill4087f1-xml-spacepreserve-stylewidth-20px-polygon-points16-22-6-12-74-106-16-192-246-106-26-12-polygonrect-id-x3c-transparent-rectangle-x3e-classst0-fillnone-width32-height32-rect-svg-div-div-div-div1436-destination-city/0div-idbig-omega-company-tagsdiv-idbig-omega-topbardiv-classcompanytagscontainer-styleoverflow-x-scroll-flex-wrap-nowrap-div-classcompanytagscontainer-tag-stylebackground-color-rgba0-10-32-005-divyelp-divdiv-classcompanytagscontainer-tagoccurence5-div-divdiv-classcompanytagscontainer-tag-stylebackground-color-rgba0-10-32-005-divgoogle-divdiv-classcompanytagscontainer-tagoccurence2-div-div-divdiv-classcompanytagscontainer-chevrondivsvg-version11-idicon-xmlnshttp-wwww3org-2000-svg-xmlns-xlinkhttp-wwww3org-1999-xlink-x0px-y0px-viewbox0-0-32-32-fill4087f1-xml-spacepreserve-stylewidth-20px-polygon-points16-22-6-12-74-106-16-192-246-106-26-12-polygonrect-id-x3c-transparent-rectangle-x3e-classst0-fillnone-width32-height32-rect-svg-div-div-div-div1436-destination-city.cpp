class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mp;
        for(auto it : paths)
            mp[it[0]] = it[1];
        
        string temp = paths[0][0];
        while(mp.find(temp) != mp.end())
            temp = mp[temp];
        
        return temp;
    }
};