//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        int finalrow = destination.first;
        int finalcol = destination.second;
        
        if(source.first == finalrow && source.second == finalcol)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<tuple<int,int,int>> q; // {distance, row, col}
        q.push(make_tuple(0, source.first, source.second));
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        
        while(!q.empty()){
            int distance = get<0>(q.front());
            int row = get<1>(q.front());
            int col = get<2>(q.front());
            q.pop();
            
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            
            for(int i = 0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 
                distance+1<dist[nrow][ncol])
                {
                    dist[nrow][ncol] = distance + 1;
                    if(nrow == finalrow && ncol == finalcol){
                        return dist[nrow][ncol];
                    }
                    q.push(make_tuple(dist[nrow][ncol], nrow, ncol));
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends