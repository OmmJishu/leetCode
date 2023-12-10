class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
            for(auto it : graph[i])
                mp[i].push_back(it);
        }
        
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> res;
        
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                dfs(i,mp,vis,pathVis,res);
            }
        }
        
        sort(begin(res),end(res));
        return res;
    }
    
private:
    // function for cycle detection
    bool dfs(int node, unordered_map<int,vector<int>> &mp, vector<int> &vis, vector<int> &pathVis, vector<int> &res){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : mp[node]){
            if(vis[it] == 0){
                if(dfs(it,mp,vis,pathVis,res) == true){
                    return true;   // cyle found
                }
            }
            else if(pathVis[it] == 1){
                return true;   // cyle found
            }
        }
        
        // if not cycle that mean safe node
        res.push_back(node);
        pathVis[node] = 0;
        return false;
    }
};