class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
            for(auto it : rooms[i])
                mp[i].push_back(it);
        }
        
        vector<int> vis(n,0);
        
        dfs(0,mp,vis);
        
        for(auto it : vis)
            if(it == 0)
                return false;
        
        return true;
    }

private:
    void dfs(int start, unordered_map<int,vector<int>> &mp, vector<int> &vis){
        vis[start] = 1;
        
        for(auto it : mp[start]){
            if(vis[it] == 0)
                dfs(it,mp,vis);
        }
    }
};