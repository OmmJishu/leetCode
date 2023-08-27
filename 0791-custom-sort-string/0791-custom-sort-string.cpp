class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        
        string ss = "";
        vector<vector<char>> res(s.size());
        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                res[mp[s[i]]].push_back(s[i]);
            }
            else
                ss += s[i];
        }
        
        string str = "";
        for(auto it : res){
            for(auto r : it)
                if(r != ' ')
                    str += r;
        }
        str += ss;
        
        return str;
    }
};