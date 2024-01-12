class Solution {
    // Bottom up Approach
private:
    int fun(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n = triangle.size();
        
        if(row == n-1) return triangle[row][col];
        if(row >= n) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = fun(row+1,col,triangle,dp);
        int downRight = fun(row+1,col+1,triangle,dp);
        
        return dp[row][col] = triangle[row][col] + min(down,downRight);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return fun(0,0,triangle,dp);
    }
};