class Solution {
public:
    string arrangeWords(string text) {
        text += ' ';
        vector<pair<int,string>> store;
        
        text[0] = tolower(text[0]);
        string s = "";
        for(int i = 0; i<text.size(); i++){
            if(text[i] == ' '){
                store.push_back({s.size(),s});
                s = "";
            }
            else
                s += text[i];
        }
        
        map<int,vector <string>> mp;
        for(auto it : store)
            mp[it.first].push_back(it.second);
        
        string res = "";
        for (auto it : mp) {
            if (mp[it.first].size() > 1) {
                int i = 0;
                while (i < mp[it.first].size()) {
                    res += mp[it.first][i++];
                    res += " ";
                }
            } 
            else 
                res += it.second[0] + " ";
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        
        return res;
    }
};