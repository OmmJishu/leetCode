class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> oneRow(m,0), oneCol(n,0);
        
        for(int i = 0; i<m; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1)
                    count++;
            }
            oneRow[i] = count;
        }
        
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<m; j++){
                if(grid[j][i] == 1)
                    count++;
            }
            oneCol[i] = count;
        }
        
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                res[i][j] = (oneRow[i] + oneCol[j]) - ((m-oneRow[i]) + (n-oneCol[j]));
            }
        }
        
        return res;
    }
};