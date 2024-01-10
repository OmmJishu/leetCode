class Solution {
private:
    int fun(int row, int col, vector<vector<int>>& og, vector<vector<int>>& dp){
        if(row == 0 && col == 0 && og[row][col] == 0) return 1;
        if(row == 0 && col == 0 && og[row][col] == 1) return dp[row][col] = 0;
        if(row < 0 || col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        if(og[row][col] == 1) return dp[row][col] = 0;
        
        int up = fun(row-1,col,og,dp);
        int left = fun(row,col-1,og,dp);
        
        return dp[row][col] =  up + left;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        // obstacleGrid = og
        int m = og.size(); 
        int n = og[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return fun(m-1,n-1,og,dp);
    }
};