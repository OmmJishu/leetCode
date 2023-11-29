class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int maxi = 1, res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    dfs(i,j,grid,vis,maxi);
                    res = max(res,maxi);
                    maxi = 1;
                }
            }
        }
        
        return res;
    }
    
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis, int &maxi){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                maxi++;
                dfs(nrow,ncol,grid,vis,maxi);
            }
        }
    }
};