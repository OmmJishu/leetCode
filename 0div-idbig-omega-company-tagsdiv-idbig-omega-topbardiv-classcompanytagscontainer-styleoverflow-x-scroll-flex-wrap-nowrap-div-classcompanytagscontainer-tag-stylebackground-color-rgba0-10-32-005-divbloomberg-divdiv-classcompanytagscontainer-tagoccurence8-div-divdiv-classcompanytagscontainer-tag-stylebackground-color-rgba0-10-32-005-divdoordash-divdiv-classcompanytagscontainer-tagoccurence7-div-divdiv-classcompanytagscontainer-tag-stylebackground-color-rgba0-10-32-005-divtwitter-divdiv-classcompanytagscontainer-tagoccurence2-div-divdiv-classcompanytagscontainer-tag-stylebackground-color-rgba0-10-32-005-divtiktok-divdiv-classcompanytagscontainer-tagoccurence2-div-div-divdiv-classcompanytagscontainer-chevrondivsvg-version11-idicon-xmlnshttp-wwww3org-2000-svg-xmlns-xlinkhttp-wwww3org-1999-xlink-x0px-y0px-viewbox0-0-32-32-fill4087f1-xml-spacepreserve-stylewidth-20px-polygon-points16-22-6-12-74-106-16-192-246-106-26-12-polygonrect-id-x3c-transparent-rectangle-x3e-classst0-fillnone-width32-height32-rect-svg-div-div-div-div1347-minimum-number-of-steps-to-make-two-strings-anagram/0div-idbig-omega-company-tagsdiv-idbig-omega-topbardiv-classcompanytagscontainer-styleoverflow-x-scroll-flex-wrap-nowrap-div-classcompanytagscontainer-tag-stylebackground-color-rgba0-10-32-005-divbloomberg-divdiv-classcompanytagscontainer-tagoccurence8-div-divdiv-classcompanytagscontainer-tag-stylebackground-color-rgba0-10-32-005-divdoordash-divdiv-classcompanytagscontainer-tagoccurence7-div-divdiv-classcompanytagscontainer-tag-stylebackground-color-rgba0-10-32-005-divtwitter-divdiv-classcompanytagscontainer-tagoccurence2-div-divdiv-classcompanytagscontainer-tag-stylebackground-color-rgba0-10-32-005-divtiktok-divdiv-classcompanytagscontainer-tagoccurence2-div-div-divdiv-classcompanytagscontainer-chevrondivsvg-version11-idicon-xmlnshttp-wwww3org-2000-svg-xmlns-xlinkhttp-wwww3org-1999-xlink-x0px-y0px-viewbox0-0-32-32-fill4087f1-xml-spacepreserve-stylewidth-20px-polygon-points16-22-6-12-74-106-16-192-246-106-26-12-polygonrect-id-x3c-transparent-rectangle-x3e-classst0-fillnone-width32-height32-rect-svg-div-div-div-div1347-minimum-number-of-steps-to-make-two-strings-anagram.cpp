class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        
        for(auto it : s) mp1[it]++;
        for(auto it : t) mp2[it]++;
        
        int res = 0;
        for(char it = 'a'; it<='z'; it++){
            if(mp2[it] < mp1[it]){
                res += mp1[it] - mp2[it];
            }
        }
        
        return res;
    }
};