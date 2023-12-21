for(int i = 0; i<vec.size(); i++){
}
}
return 0;
}
private:
void dfs(int row, int col, queue<pair<int,int>> &q, vector<vector<int>>& grid, vector<vector<int>> &vis){
vis[row][col] = 1;
q.push({row,col});
int n = grid.size();
int delRow[] = {-1,0,1,0};
int delCol[] = {0,1,0,-1};
for(int i = 0; i<4; i++){
int nrow = row+delRow[i];
int ncol = col+delCol[i];
if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
dfs(nrow,ncol,q,grid,vis);
}
}
}
};
```