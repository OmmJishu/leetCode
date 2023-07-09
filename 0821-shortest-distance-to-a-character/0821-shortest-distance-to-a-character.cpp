class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(),0);
        map<char,vector<int>> mp;
        
        for(int i = 0; i<s.size(); i++)
            if(s[i] == c)
                mp[s[i]].push_back(i);
        
        for(int i = 0; i<s.size(); i++){
            auto it = mp[c];
            int mini = INT_MAX;
            for(int j = 0; j<it.size(); j++)
                mini = min(mini, abs(i-it[j]));
        
            res[i] = mini;
        }
        
        return res;
    }
};