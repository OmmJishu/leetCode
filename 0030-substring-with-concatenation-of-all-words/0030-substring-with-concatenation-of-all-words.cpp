class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> mp;
        for(auto it : words)
            mp[it]++;
        
        int lenWindow = words.size()*words[0].size();
        
        int slen = s.size(), wordlen = words[0].size();
        for(int i = 0; (i + lenWindow) <= slen; i++) 
            if(checkSubstring(mp, s.substr(i, lenWindow), wordlen)) 
                res.push_back(i);
        
        return res;
    }
    
private:
    bool checkSubstring(unordered_map<string, int> mp, string s, int wordLen) {
        
        for(int j = 0; j<s.size(); j += wordLen){
            string tofind = s.substr(j, wordLen);
            
            if(mp.find(tofind) != mp.end()) {
                if(mp[tofind]-- == 0) 
                    return false;
            } 
            else 
                return false;
        }
        
        return true;
    }
};