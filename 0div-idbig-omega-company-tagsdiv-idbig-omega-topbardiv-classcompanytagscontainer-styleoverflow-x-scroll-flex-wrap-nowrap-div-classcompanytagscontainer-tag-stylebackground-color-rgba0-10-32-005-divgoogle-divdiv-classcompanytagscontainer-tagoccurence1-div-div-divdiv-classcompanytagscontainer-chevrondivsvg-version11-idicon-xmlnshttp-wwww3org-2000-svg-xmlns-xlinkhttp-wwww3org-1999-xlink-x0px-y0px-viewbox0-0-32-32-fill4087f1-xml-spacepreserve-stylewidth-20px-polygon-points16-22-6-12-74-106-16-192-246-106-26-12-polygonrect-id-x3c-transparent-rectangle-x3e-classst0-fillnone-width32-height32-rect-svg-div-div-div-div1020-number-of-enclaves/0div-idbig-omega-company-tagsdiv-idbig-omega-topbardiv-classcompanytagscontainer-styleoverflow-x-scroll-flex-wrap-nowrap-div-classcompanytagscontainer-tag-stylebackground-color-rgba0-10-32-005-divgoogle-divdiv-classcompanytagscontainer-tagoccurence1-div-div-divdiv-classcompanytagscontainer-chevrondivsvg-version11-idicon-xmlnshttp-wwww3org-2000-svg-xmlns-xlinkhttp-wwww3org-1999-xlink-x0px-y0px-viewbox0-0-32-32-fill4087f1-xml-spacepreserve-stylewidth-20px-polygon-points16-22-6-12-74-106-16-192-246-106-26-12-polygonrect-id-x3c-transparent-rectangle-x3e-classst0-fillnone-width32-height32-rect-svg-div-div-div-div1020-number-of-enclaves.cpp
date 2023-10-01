class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        int i = 0;
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 1){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
        i = n-1;
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 1){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
        
        int j = 0;
        for(int k = 0; k<n; k++){
            if(mat[k][j] == 1){
                vis[k][j] = 1;
                q.push({k,j});
            }
        }
        j = m-1;
        for(int k = 0; k<n; k++){
            if(mat[k][j] == 1){
                vis[k][j] = 1;
                q.push({k,j});
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k = 0; k<4; k++){
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 1 && 
                vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        int cnt = 0;
        for(int p = 0; p<n; p++){
            for(int s = 0; s<m; s++){
                if(mat[p][s] == 1 && vis[p][s] == 0){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};