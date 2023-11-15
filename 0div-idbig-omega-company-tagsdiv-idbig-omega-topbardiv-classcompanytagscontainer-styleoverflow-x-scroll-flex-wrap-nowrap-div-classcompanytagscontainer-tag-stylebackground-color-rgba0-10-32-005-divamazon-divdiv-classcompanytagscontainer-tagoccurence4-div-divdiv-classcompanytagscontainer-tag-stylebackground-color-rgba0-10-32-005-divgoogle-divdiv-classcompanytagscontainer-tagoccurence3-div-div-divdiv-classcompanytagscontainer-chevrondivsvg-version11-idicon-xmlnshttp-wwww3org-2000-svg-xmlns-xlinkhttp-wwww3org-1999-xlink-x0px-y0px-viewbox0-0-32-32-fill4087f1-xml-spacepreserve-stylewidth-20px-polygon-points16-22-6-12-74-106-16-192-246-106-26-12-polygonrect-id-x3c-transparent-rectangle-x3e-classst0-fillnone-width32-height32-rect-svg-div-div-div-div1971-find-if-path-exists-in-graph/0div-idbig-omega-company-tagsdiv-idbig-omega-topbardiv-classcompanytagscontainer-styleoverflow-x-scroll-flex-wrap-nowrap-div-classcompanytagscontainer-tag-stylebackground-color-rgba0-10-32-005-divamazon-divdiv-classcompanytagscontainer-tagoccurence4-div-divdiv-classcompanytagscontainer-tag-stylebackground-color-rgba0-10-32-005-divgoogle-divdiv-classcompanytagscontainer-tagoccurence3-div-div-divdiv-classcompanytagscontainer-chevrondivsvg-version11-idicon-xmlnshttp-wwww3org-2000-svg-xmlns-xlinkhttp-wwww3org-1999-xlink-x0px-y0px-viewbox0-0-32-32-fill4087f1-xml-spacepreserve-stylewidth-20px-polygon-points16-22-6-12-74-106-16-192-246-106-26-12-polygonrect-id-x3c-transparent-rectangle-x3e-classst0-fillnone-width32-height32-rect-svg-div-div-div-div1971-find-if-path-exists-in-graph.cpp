class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        return dfs(source,mp,vis,destination);
    }
    
private:
    bool dfs(int &source, unordered_map<int,vector<int>> &mp, vector<int> &vis, int &destination){
        if(source == destination)
            return true;
        
        vis[source] = 1;
        for(auto it : mp[source]){
            if(vis[it] == 0)
                if(dfs(it,mp,vis,destination)){
                    return true;
                }
        }
        
        return false;
    }
};