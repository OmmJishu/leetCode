class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(), source = 0, target = n-1;
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
            for(auto it : graph[i])
                mp[i].push_back(it);
        }
        vector<int> vis(n,0);
        vector<vector<int>> allPath;
        vector<int> currentPath;
        
        dfs(source,mp,vis,allPath,currentPath,target);
        
        return allPath;
    }
    
private:
    void dfs(int source, unordered_map<int,vector<int>> &mp, vector<int> &vis, vector<vector<int>> &allPath, vector<int> &currentPath, int target){
        currentPath.push_back(source);
        vis[source] = 1;
        
        if(source == target){
            allPath.push_back(currentPath);
        }
        
        for(auto it : mp[source]){
            if(vis[it] == 0){
                dfs(it,mp,vis,allPath,currentPath, target);
            }
        }
        
        vis[source] = 0;
        currentPath.pop_back();
    }
};