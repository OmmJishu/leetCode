//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& temp, int row0, int col0) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            temp.push_back({cur.first - row0, cur.second - col0});
            
            for (int k = 0; k < 4; k++) {
                int nrow = cur.first + delRow[k];
                int ncol = cur.second + delCol[k];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    bfs(i, j, grid, vis, temp, i, j);
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