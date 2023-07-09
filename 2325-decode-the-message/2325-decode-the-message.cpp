class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mp;
        char ch = 'a';
        for(auto it : key){
            if(it == ' ')
                continue;
            else if(mp.find(it) == mp.end())
                mp[it] = ch++;
        }
        
        string s = "";
        for(auto it : message){
            if(it == ' ')
                s += it;
            else{
                s += mp[it];
            }
        }
        
        return s;    
    }
};