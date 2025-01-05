class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int,char> mp;
        for(int i = 0; i<26; i++) mp[i] = i+'a';
        
        int pref[50001] = {0};
        for(int i = 0; i<shifts.size(); i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir == 1){
                pref[start]++;
                pref[end+1]--;
            }
            else{
                pref[start]--;
                pref[end+1]++;
            }
        }
        
        for(int i = 1; i<50001; i++){
            pref[i] += pref[i-1];
        }
        
        for(int i = 0; i<s.size(); i++){
            int idx = s[i] - 'a';
            idx = (idx + (pref[i]%26 + 26))%26; // pref[i] % 26: This ensures that the shift amount is within the bounds of the alphabet (since there are 26 letters). If the pref[i] value is greater than 26 or negative, taking the modulo ensures that it wraps around the alphabet correctly. +26  if pref[i]%26 give -ve value then +26 make it inbetween from 0 to 25 and then %26 for final 0 to 25
            s[i] = mp[idx];
        }
        
        return s;
    }
};