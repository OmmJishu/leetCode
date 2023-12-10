//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<V; i++){
            for(auto it : adj[i])
                mp[i].push_back(it);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> res;
        
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                dfs(i,mp,vis,pathVis,res);
            }
        }
        
        sort(begin(res),end(res));
        return res;
    }
    
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends