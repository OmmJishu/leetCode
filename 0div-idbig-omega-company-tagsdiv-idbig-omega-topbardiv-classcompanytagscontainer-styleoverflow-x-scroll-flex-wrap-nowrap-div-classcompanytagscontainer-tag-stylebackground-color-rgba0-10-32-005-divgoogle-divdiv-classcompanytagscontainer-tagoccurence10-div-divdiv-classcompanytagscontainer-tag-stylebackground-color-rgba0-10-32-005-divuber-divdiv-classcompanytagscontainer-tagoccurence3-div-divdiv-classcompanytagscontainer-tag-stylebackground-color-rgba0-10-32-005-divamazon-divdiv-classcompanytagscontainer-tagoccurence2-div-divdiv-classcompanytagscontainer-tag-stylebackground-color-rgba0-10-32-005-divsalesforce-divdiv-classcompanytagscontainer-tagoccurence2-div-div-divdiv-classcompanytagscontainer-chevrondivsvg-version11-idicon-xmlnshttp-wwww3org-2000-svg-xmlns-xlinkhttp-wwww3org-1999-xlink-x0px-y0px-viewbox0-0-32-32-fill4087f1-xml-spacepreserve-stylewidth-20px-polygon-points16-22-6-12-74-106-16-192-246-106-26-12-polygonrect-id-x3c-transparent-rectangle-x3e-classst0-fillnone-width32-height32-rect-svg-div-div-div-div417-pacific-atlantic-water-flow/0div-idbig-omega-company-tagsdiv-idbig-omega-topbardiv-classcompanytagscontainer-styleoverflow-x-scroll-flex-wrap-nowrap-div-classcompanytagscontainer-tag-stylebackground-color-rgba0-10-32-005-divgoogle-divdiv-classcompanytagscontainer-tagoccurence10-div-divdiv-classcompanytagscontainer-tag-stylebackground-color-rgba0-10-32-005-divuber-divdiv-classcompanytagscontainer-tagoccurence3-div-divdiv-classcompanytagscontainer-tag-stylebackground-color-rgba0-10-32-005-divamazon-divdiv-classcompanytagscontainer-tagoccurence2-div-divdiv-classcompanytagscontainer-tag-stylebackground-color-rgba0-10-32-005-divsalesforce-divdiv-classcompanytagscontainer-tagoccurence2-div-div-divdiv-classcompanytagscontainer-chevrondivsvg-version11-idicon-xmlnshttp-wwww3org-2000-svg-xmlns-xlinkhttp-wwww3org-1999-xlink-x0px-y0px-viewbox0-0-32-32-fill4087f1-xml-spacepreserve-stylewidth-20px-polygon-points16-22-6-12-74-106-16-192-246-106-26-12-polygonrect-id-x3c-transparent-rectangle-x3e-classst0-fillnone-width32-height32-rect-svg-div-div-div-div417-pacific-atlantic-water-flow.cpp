class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> pacificReach(row,vector<int>(col,0));
        vector<vector<int>> atlanticReach(row,vector<int>(col,0));
        
        for(int i = 0; i<row; i++){
            dfs(heights,i,0,pacificReach);
            dfs(heights,i,col-1,atlanticReach);
        }
        
        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, pacificReach);
            dfs(heights, row - 1, j, atlanticReach);
        }
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pacificReach[i][j] == 1 && atlanticReach[i][j] == 1){
                    res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>> &vis)
    {
        int n = heights.size();
        int m = heights[0].size();
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
        
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && heights[nrow][ncol]>=heights[row][col] && vis[nrow][ncol] == 0)
            {
                dfs(heights,nrow,ncol,vis);
            }
        }
    }
};