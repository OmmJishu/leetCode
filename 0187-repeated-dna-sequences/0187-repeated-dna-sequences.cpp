class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        if(s.size()<=10)
            return {};
        
        string window = "";
        for(int i = 0; i<10; i++){
            window += s[i];
        }
        mp[window]++;
        
        for(int i = 1; i+10<=s.size(); i++){
            window += s[i+10-1];
            string str = window.substr(i,window.length()-1);
            mp[str]++;
        }
        
        vector<string> res;
        for(auto it : mp){
            if(it.second > 1)
                res.push_back(it.first);
        }
        
        return res;
    }
};