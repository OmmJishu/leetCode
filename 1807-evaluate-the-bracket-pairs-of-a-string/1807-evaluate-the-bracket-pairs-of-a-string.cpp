class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto it : knowledge)
            mp[it[0]] = it[1];
        
        string res = "";
        int i = 0;
        while(i<s.size()){
            if(s[i] == '('){
                string tmp = "";
                i++;
                while(s[i] != ')')
                    tmp += s[i++];
                
                if(mp.find(tmp) != mp.end())
                    res += mp[tmp];
                else
                    res += "?"; 
                i++;
            }
            else{
                res += s[i]; 
                i++;
            }
        }
        
        return res;
    }
};