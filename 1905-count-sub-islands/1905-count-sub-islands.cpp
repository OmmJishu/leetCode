class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] == 0 && grid2[i][j] == 1 && grid1[i][j] == 1){
                    bool mark = true;
                    dfs(i,j,grid1,grid2,vis,mark);
                    if(mark == true){
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
    
private:
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &vis, bool &mark)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        
        for(int i = 0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid2[nrow][ncol]==1  && !vis[nrow][ncol]){
                if(grid1[nrow][ncol]==0 && grid2[nrow][ncol]==1) 
                    mark = false;
                dfs(nrow,ncol,grid1,grid2,vis,mark);
            }
        }
    }
};