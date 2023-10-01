//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis, 
    vector<pair<int,int>> &temp, int row0, int col0)
    {
        vis[i][j] = 1;
        temp.push_back({i-row0,j-col0});
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int k = 0; k<4; k++){
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
            {
                dfs(nrow,ncol,grid,vis,temp,row0,col0);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,grid,vis,temp,i,j);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends