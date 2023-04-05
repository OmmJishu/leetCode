class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for (auto it : strs) {
            string temp = it; 
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }
        vector<vector<string>> res;
        for (auto it : mp)
            res.push_back(it.second);
        return res;
    }
};