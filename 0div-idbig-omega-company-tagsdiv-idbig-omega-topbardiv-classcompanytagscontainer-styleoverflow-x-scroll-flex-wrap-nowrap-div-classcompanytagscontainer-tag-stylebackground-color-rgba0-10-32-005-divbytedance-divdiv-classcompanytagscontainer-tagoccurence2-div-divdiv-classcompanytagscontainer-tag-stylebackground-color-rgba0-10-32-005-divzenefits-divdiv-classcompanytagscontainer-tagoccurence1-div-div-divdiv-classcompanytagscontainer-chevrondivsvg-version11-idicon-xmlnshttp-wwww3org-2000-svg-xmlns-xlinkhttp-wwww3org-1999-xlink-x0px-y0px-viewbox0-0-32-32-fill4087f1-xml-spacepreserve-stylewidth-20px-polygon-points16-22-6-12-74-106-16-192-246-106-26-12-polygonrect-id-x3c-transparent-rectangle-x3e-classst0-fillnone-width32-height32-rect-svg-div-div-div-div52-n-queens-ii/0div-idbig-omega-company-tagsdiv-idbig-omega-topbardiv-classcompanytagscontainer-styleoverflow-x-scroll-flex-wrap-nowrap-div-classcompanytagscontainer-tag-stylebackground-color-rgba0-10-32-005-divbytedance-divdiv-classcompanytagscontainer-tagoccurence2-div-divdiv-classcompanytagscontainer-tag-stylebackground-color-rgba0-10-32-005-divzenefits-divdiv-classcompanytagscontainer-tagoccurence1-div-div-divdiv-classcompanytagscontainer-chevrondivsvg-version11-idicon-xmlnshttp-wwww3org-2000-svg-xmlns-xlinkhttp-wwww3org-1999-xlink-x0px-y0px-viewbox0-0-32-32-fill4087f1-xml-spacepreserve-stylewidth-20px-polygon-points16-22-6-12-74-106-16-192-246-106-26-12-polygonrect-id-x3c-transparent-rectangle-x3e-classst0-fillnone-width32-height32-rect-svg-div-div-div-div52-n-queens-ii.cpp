class Solution {
    int res = 0;
    
    void solve(int col, int n, vector<int> &currRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, vector<string> &curr)
    {
        if(col == n){
            res++;
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(currRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[col - row + n-1] == 0)
            {
                currRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[col - row + n-1] = 1;
                curr[row][col] = 'Q';
                
                solve(col+1, n, currRow, lowerDiagonal, upperDiagonal, curr);
        
                // backtrack
                currRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[col - row + n-1] = 0;
                curr[row][col] = '.';
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        vector<int> currRow(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDiagonal(2*n-1,0);
        
        vector<string> curr(n);
        string s(n,'.');
        for(int i = 0; i<n; i++) curr[i] = s;
        
        solve(0,n,currRow,lowerDiagonal,upperDiagonal, curr); // passed 0th col
        
        return res;
    }
};