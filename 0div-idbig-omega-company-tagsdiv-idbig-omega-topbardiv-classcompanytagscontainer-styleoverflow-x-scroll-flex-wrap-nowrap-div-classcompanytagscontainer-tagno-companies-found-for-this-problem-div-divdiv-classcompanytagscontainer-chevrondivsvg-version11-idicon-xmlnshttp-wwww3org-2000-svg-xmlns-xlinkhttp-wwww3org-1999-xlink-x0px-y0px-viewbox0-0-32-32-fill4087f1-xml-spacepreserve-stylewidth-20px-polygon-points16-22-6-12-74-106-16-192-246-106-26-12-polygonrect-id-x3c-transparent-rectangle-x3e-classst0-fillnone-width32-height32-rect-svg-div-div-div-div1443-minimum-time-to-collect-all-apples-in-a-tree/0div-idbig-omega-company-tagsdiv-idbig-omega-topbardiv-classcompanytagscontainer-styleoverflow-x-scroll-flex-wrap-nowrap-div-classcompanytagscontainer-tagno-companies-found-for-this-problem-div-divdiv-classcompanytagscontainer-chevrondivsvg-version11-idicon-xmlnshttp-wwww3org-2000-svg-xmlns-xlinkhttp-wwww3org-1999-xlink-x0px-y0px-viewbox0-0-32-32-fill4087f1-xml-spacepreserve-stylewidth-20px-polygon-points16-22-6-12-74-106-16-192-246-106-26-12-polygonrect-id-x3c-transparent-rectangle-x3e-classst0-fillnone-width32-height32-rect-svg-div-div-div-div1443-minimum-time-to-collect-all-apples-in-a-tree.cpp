class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> mp;
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        int cnt = 0;
        
        dfs(0,mp,hasApple,vis,cnt);
        
        return cnt*2;
    }
    
private:
    void dfs(int node, unordered_map<int,vector<int>> &mp, vector<bool>& hasApple, vector<int> &vis, int &cnt){
        vis[node] = 1;
        
        for(auto it : mp[node]){
            if(vis[it] == 0){
                dfs(it,mp,hasApple,vis,cnt);
                if(hasApple[it] == true){
                    cnt++;
                    hasApple[node] = true; // make parent true as cahild has been found true   to make cnt++ while backtracking
                }
            }
        }
    }
};