class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i = 0;

        unordered_map<char, char> mp;
        unordered_map<char, char> revMp;
        
        for (; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                if (revMp.find(t[i]) == revMp.end()) {
                     mp[s[i]] = t[i]; // char is already mapped to a different character
                     revMp[t[i]] = s[i];
                }
            }
        }
        
        i = 0;
        for(i = 0; i<s.size(); i++)
            if(mp[s[i]] != t[i])
                return false;
        
        return i == s.size();
    }
};