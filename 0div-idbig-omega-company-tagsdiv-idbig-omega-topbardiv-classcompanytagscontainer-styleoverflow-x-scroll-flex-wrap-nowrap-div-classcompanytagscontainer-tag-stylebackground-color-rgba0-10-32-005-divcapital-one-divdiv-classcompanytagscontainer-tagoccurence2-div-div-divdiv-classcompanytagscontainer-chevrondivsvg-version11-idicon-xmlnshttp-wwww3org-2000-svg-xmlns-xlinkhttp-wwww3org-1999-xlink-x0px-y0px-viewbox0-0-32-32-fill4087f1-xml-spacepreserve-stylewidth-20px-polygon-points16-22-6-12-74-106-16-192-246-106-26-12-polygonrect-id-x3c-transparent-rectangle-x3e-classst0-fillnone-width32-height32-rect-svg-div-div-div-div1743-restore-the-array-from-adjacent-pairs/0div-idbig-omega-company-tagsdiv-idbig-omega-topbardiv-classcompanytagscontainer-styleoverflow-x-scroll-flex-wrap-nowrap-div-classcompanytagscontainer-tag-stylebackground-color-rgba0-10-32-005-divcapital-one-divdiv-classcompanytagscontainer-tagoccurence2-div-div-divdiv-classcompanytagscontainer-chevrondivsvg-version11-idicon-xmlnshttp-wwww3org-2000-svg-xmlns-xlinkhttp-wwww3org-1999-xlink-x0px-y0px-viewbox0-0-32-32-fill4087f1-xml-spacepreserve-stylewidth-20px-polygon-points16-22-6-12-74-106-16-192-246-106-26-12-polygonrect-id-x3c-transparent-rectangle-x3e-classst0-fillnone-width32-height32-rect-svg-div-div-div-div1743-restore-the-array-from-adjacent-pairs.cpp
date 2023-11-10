class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,int> mp;
        for(auto it : adjacentPairs){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        
        int first;
        for(auto it : mp){
            if(it.second == 1){
                first = it.first;
                break;
            }
        }
        
        map<int,vector<int>> mp1;
        for(auto it : adjacentPairs){
            mp1[it[0]].push_back(it[1]);
            mp1[it[1]].push_back(it[0]);
        }
        
        unordered_set<int> st;
        vector<int> res;
        
        dfs(first,res,mp1,st);
        
        return res;
    }
    
private:
    void dfs(int first, vector<int> &res, map<int,vector<int>> &mp1, unordered_set<int> &st){
        st.insert(first);
        res.push_back(first);
        
        for(auto it : mp1[first]){
            if(st.find(it) == st.end()){
                dfs(it,res,mp1,st);
            }
        }
    }
};