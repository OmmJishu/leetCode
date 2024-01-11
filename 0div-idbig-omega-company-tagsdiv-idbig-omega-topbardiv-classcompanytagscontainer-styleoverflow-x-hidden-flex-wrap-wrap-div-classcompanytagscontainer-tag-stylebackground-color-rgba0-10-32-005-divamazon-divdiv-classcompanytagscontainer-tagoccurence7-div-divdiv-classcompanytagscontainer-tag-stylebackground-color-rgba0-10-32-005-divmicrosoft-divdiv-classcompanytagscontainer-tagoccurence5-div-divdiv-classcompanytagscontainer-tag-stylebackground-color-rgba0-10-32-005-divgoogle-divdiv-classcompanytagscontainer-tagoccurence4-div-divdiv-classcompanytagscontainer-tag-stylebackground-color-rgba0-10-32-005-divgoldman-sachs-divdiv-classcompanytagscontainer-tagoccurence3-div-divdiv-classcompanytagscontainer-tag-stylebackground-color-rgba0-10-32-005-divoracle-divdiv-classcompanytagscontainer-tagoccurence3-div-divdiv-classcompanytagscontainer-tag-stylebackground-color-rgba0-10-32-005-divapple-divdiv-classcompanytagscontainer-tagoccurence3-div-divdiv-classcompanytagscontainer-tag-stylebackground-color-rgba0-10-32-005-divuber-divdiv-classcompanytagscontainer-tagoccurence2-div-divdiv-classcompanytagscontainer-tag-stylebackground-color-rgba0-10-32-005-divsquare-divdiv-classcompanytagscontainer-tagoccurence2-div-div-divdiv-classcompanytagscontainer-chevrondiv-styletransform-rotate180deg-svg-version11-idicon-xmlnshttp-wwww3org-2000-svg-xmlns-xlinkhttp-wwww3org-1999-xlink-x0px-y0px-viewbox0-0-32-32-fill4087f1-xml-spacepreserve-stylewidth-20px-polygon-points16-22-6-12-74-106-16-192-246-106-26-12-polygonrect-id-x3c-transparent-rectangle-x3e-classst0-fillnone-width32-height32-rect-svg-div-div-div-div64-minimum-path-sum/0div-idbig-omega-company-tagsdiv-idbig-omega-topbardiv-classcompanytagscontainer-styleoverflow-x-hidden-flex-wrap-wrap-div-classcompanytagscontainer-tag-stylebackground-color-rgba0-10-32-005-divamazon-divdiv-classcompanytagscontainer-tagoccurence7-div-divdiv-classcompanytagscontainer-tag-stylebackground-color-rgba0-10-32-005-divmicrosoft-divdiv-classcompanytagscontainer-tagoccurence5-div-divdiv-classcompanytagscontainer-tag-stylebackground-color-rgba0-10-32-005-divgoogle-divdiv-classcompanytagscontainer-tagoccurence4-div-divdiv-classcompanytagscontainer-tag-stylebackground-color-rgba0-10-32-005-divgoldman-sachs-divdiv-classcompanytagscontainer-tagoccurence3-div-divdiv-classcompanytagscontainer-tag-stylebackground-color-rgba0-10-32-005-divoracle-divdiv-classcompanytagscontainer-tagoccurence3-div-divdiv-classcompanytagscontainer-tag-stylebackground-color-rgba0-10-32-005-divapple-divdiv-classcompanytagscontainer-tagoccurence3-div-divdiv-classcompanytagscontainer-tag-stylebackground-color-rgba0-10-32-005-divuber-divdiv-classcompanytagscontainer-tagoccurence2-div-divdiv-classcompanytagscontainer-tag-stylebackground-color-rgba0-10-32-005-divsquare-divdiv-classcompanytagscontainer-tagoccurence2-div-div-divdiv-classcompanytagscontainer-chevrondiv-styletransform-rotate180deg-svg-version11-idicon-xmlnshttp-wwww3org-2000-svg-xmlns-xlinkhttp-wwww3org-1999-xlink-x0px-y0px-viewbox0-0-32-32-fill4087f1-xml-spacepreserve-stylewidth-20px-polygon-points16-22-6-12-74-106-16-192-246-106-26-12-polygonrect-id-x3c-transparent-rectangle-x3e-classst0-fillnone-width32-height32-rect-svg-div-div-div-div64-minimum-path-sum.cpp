class Solution {
private:
    int fun(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0)
            return grid[row][col];
        
        if(row < 0 || col < 0)
            return INT_MAX;
        
        if(dp[row][col] != 0)
            return dp[row][col];
        
        return dp[row][col] = grid[row][col] + min(fun(row-1,col,grid,dp), fun(row,col-1,grid,dp));
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        return fun(m-1,n-1,grid,dp);
    }
};