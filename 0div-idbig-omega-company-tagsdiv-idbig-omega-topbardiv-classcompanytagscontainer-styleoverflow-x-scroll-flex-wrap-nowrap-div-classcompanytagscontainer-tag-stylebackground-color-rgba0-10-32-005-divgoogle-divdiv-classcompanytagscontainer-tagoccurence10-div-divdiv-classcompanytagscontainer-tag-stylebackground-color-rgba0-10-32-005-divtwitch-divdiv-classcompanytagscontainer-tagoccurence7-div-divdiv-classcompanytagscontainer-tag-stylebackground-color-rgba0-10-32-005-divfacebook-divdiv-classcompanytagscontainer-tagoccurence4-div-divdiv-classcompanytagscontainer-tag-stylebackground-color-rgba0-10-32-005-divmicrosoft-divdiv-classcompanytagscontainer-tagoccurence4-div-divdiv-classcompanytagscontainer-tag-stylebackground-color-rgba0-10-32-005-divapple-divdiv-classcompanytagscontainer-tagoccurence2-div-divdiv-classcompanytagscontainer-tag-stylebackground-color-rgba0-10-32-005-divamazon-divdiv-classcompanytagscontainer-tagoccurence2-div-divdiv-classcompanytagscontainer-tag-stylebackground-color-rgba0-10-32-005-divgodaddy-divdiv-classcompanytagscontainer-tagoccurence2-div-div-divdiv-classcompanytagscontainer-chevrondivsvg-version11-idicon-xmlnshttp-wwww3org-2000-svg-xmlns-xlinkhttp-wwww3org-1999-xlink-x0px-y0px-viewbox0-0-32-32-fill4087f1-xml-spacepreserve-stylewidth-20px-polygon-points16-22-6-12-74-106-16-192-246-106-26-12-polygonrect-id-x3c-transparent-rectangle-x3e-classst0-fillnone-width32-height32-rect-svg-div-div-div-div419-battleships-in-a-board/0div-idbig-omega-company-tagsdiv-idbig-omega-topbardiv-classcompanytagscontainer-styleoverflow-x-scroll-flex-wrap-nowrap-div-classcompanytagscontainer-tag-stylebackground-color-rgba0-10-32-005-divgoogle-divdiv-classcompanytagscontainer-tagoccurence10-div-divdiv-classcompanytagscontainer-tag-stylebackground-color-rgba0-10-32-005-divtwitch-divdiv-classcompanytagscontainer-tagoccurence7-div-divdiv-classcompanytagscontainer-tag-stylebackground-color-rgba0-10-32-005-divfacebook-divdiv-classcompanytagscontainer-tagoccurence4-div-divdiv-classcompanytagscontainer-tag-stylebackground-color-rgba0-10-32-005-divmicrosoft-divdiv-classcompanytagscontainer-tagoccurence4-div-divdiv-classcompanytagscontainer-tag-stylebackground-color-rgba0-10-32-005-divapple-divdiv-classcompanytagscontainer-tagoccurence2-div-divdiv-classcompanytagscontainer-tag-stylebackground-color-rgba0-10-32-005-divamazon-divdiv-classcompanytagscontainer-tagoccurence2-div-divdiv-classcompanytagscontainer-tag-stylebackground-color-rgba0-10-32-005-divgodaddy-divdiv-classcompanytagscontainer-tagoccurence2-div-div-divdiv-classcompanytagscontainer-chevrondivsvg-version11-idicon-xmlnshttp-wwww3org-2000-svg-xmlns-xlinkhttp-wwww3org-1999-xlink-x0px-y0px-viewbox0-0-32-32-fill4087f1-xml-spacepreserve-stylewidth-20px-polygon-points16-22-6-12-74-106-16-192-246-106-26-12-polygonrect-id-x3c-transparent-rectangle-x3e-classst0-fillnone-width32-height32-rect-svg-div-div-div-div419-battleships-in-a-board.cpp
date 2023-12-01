class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='X' && vis[i][j]==0){
                    dfs(i,j,board,vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='X' && vis[nrow][ncol]==0){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
};