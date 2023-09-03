class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // {{row,col},time}
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(grid[row][col] == 2){
                    q.push({{row,col},0});
                    vis[row][col] = 1;
                }
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int tm = 0;
        
        while(!q.empty()){
            int ro = q.front().first.first;
            int cl = q.front().first.second;
            int time = q.front().second;
            q.pop();
            tm = max(tm,time);
            
            for(int i = 0; i<4; i++){
                int nrow = ro + delRow[i];
                int ncol = cl + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    return -1;
                }
            }
        }
        
        return tm;
    }
};