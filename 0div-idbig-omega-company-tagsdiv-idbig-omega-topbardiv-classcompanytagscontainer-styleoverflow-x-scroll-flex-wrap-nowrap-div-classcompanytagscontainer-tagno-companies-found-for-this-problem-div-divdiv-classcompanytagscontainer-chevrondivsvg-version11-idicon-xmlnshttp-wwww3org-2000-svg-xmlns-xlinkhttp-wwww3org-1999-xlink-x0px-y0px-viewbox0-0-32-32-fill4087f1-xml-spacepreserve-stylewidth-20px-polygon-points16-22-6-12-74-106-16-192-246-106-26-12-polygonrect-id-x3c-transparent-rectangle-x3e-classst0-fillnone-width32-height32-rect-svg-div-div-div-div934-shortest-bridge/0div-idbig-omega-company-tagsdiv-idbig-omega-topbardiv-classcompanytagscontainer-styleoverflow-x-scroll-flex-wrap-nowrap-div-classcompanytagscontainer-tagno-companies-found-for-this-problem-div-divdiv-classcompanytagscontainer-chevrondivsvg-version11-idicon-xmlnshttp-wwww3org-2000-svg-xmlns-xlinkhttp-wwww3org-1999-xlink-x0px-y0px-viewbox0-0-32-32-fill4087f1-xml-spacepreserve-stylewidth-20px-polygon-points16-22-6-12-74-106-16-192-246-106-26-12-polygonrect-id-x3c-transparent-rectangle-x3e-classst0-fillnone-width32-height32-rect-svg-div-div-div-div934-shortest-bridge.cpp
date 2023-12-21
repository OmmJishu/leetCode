class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        
        bool mark = false;
        queue<pair<int,int>> q;  //  {row,col,steps}
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && mark==false){
                    dfs(i,j,q,grid);
                    mark = true;
                    break;
                }
            }
            if(mark==true) break;
        }
        
        int mini = INT_MAX, dist = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int sz = q.size();
            
            while(sz-- > 0){
                int ro = q.front().first;
                int cl = q.front().second;
                q.pop();
                
                for(int i = 0; i<4; i++){
                    int nrow = ro + delRow[i];
                    int ncol = cl + delCol[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        return dist;
                    }
                    else if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol] = 2; // mark visited
                    }
                }
            }
            
            ++dist;
        }
        
        return -1;
    }
    
private:
    void dfs(int row, int col, queue<pair<int,int>> &q, vector<vector<int>>& grid){
        q.push({row,col});
        grid[row][col] = 2;
        int n = grid.size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                dfs(nrow,ncol,q,grid);
            }
        }
    }
};