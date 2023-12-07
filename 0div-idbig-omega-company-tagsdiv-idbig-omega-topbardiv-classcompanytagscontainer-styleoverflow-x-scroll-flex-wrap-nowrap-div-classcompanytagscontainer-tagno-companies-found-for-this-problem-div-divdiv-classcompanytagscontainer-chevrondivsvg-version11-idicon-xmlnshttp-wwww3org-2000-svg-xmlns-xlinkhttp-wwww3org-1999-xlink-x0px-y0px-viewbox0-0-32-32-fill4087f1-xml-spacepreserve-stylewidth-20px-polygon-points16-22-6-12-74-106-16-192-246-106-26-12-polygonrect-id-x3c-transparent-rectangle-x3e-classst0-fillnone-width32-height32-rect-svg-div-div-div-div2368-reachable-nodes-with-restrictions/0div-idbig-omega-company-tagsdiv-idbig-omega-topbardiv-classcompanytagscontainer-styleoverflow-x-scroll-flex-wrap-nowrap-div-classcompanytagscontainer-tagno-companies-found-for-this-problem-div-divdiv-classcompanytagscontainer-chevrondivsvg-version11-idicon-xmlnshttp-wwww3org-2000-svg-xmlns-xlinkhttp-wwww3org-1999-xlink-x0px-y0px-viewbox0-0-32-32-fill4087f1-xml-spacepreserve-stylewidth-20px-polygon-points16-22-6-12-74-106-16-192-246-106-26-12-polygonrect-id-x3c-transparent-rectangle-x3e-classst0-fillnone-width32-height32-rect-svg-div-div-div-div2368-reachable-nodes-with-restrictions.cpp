class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n,0);
        for(auto it : restricted)
            vis[it] = 1;
        
        unordered_map<int,vector<int>> mp;
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        int cnt = 0;
        dfs(0,mp,vis,cnt);
        
        return cnt;
    }
    
private:
    void dfs(int node, unordered_map<int,vector<int>> &mp, vector<int> &vis, int &cnt){
        vis[node] = 1;
        cnt++;
        for(auto it : mp[node]){
            if(vis[it] == 0){
                dfs(it,mp,vis,cnt);
            }
        }
    }
};