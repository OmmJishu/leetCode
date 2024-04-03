class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,board,word,vis)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
private:
    int k = 0;
    
    bool dfs(int row, int col, vector<vector<char>>& board, string word, vector<vector<int>> &vis)
    {
        int ro = board.size(), cl = board[0].size();
        if(k == word.size() - 1) return true;
        if(row >= ro || col >= cl || row < 0 || col < 0 || vis[row][col] == 1) 
            return false;
        
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<ro && ncol>=0 && ncol<cl && !vis[nrow][ncol] && board[nrow][ncol] == word[k+1])
            {
                k += 1;
                if(dfs(nrow,ncol,board,word,vis))
                    return true;
                
                k -= 1; // backtrack if the path is not valid
            }
        }
        
        vis[row][col] = 0; // backtrack
        
        return false;
    }
};