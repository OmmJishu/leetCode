class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(auto it : chars)
            mp[it]++;
        
        int res = 0;
        for(auto it : words){
            bool isGood = true;
            unordered_map<char,int> mp2(mp);
            
            for(auto ch : it){
                if(mp2.find(ch) != mp2.end() && mp2[ch] > 0){
                    mp2[ch]--;
                }
                else{
                    isGood = false;
                    break;
                }
            }
            
            if(isGood){
                res += it.size();
            }
        }
        
        return res;
    }
};