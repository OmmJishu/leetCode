class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        
        for(auto it : word1)
            hash1[it-'a']++;
        for(auto it : word2)
            hash2[it-'a']++;
        for(int i = 0; i<26; i++){
            if(abs(hash1[i]-hash2[i])>3){
                return false;
            }
        }
        return true;
    }
};