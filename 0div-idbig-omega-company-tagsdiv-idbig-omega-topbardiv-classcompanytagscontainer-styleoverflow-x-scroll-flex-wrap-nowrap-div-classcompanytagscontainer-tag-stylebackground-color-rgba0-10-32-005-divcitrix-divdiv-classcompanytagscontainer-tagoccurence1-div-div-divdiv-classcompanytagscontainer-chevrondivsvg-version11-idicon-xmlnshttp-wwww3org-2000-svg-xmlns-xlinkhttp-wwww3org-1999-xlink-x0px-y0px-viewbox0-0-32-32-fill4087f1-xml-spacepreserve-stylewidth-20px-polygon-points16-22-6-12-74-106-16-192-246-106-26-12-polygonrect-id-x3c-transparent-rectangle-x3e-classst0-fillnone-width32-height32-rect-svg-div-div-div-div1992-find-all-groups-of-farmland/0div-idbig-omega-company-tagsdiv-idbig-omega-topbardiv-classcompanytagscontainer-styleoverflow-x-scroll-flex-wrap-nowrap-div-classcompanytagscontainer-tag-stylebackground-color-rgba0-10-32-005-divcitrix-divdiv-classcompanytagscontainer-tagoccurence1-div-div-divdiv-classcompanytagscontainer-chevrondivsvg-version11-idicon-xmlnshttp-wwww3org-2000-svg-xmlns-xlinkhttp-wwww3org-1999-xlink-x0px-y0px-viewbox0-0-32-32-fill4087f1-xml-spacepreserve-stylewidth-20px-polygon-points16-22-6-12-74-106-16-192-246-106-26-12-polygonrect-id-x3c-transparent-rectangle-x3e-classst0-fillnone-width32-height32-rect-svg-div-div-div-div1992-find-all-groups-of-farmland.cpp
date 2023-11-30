class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> res;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(land[i][j] == 1 && vis[i][j] == 0){
                    vector<int> temp(4,0);
                    temp[0] = i;
                    temp[1] = j;
                    temp[2] = i;
                    temp[3] = j;
                    dfs(i,j,land,vis,temp);
                    res.push_back(temp);
                }
            }
        }
        
        return res;
    }
    
private:
    void dfs(int row, int col, vector<vector<int>>& land, vector<vector<int>> &vis, vector<int>&temp){
        int n = land.size();
        int m = land[0].size();
        vis[row][col] = 1;
        
        int delRow[] = {0,1,0,-1};
        int delCol[] = {-1,0,1,0};
        
        for(int i = 0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && land[nrow][ncol]==1 && vis[nrow][ncol]==0){
                if(nrow >= temp[2]){
                    temp[2] = nrow;
                    temp[3] = ncol;
                }
                dfs(nrow,ncol,land,vis,temp);
            }
        }
    }
};