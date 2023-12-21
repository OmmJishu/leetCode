//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto it : edges){
            int i = it[0];
            int j = it[1];
            int wt = it[2];
            dist[i][j] = wt;
            dist[j][i] = wt;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        for(int via = 0; via<n; via++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][via]==1e9 || dist[via][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        
        int cnt = n, ans;
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    c++;
                }
            }
            
            if(c<=cnt){
                cnt = c;
                ans = i;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends