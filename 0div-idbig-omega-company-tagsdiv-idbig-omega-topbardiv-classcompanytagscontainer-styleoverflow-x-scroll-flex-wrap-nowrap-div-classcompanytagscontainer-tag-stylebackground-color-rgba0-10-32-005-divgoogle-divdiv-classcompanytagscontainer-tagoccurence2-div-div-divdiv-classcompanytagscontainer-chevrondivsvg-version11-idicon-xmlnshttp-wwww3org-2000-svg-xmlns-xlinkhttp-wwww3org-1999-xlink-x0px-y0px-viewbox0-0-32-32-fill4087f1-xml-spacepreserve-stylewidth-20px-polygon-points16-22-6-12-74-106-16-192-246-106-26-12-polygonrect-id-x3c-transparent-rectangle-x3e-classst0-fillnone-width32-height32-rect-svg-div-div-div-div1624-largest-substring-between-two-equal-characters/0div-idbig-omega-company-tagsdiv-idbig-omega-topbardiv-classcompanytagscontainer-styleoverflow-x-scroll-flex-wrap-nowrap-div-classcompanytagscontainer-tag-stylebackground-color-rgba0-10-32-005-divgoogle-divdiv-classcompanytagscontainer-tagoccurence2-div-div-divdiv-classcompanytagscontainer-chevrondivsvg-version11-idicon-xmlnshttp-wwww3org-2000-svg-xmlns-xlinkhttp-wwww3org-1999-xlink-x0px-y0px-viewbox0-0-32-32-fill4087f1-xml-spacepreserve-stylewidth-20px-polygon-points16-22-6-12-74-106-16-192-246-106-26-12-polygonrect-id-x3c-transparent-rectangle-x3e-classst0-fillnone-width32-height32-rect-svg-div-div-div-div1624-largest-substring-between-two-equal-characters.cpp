class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int i = 0, j = 0, n = s.size(), maxi = -1;
        
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                int len = j - mp[s[j]] - 1;
                maxi = max(maxi, len);
            }
            else{
                mp[s[j]] = j;
            }
            
            j++;
        }
        
        return maxi;
    }
};