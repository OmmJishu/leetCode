class Solution {
public:
    char repeatedCharacter(string s) {
        
        unordered_map<char,int> mp;
        char res;
        for(auto it: s){
            mp[it]++;
            if(mp[it] == 2){
                res = it;
                break;
            }
        }
        return res;
    }
};