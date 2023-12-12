class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> mp;
        for(auto it : accounts){
            for(int i = 1; i<it.size()-1; i++){
                mp[it[i]].push_back(it[i+1]);
                mp[it[i+1]].push_back(it[i]);
            }
        }
        
        unordered_set<string> vis;
        vector<vector<string>> res;
        
        for(auto it : accounts){
            if(vis.find(it[1]) == vis.end()){
                res.push_back({it[0]});
                dfs(it[1],mp,vis,res);
                sort(res.back().begin()+1, res.back().end());
            }
        }
        
        return res;
    }
    
private:
    void dfs(string &email, unordered_map<string,vector<string>> &mp, unordered_set<string> &vis, vector<vector<string>> &res){
        vis.insert(email);
        res.back().push_back(email);
        
        for(auto it : mp[email]){
            if(vis.find(it) == vis.end()){
                dfs(it,mp,vis,res);
            }
        }
    }
};