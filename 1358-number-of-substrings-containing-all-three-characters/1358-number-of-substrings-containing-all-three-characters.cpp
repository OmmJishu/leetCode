class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.size(), j = 0;
        unordered_map<char,int> mp;
        
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                res += (n-i);
                mp[s[j++]]--;
            }
        }
        
        return res;
    }
};