//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,long long>>> adj;
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            long long time = it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        
        vector<long long> dist(n,1e18);  dist[0] = 0;
        vector<long long> ways(n,0);  ways[0] = 1;
        
        // min heap of type {time, node} to get minimum distance at each step
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            
            if(node == n-1) break;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long adjTime = it.second;
                
                if(time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    ways[adjNode] = ways[node]; // Important
                    pq.push({dist[adjNode],adjNode});
                }
                else if(time + adjTime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % 1000000007;
                }
            }
        }
        
        return ways[n-1] % 1000000007;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends