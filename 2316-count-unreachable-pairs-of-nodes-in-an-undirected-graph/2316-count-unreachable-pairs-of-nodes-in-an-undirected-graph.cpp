class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adjLs[n];
        for(auto it : edges){
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        vector<long long> store;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int cnt = 0;
                dfs(i,adjLs,vis,cnt);
                store.push_back(cnt);
            }
        }
        
        long long sum = accumulate(store.begin(),store.end(),0LL);
        long long ans = 0;
        for(int i = 0; i<store.size(); i++){
            sum -= store[i];
            ans += (store[i]*sum);
        }
       
        return ans;
    }
    
private:
    void dfs(int node, vector<int> adjLs[], vector<int>& vis, int &cnt){
        vis[node] = 1;
        cnt++;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis,cnt);
            }
        }
   }
};