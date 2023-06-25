class Solution {
public:
    string sortString(string s) {
        map<char,int> mp;
        for(auto it : s)
            mp[it]++;
        
        string res = "";
        
        while(mp.size()!=0){
            for(auto it = 'a'; it<='z'; it++){
                if(mp.find(it) != mp.end()){
                    res = res + it;
                    mp[it]--;
                    if(mp[it] == 0)
                        mp.erase(it);
                }
            }
            for(auto it = 'z'; it>='a'; it--){
                if(mp.find(it) != mp.end()){
                    res = res + it;
                    mp[it]--;
                    if(mp[it] == 0)
                        mp.erase(it);
                }
            }
        }
        
        return res;
    }
};