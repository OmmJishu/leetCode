class Solution {
private:
    int fun(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int m = matrix.size();
        
        if(col < 0 || col>= m) return 1e9;
        if(row == m-1) return dp[row][col] = matrix[row][col];
    
        if(dp[row][col] != 1e9) return dp[row][col];
        
        int leftDown = fun(row + 1, col-1, matrix, dp);
        int down = fun(row + 1, col, matrix, dp);
        int rightDown = fun(row + 1, col +1, matrix, dp);
        
        return dp[row][col] = min(leftDown, min(down, rightDown)) + matrix[row][col];
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> dp(m,vector<int>(m,1e9));
        
        int res = INT_MAX;
        for(int i = 0; i<m; i++){
            int sum = fun(0,i,matrix,dp);
            res = min(res,sum);
        }
        
        return res;
    }
};