class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,set<char>> mp;
        for(int i = 1; i<rings.size(); i=i+2){
            char ch = rings[i];
            mp[ch-'0'].insert(rings[i-1]);
        }
        
        int count = 0;
        for(auto it : mp)
            if(it.second.size() == 3)
                count++;
        
        return count;
    }
};