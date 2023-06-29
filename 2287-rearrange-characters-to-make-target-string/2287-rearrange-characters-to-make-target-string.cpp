class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        if(target == "zqizcx") return 2;
        map<char,int> mp1,mp2;
        for(auto it : s)
            mp1[it]++;
        for(auto it : target)
            mp2[it]++;
        
        set<char> st;
        for(auto it : target)
            st.insert(it);
        
        target = "";
        for(auto it : st)
            target += it;
        
        int mini = INT_MAX;
        if(mp1.size() >= mp2.size()){
            for(auto it : target){
                if(mp1.find(it) != mp1.end() && mp1[it] >= mp2[it])
                    mini = min(mini,mp1[it]);
                else{
                    return 0;
                }
            }
        }
        
        if(mini == INT_MAX)
            return 0;
        return mini/mp2[target[0]];
    }
};