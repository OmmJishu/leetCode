class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(auto it : chars)
            mp[it]++;
        
        int res = 0;
        for(auto it : words){
            
            string s = "";
            bool isGood = true;
            unordered_map<char,int> mp2(mp);
            
            for(auto a : it){
                if(mp2.find(a) != mp2.end() && mp2[a] > 0){
                    mp2[a]--;
                    s += a;
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

