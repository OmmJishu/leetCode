class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0;
        vector<int> ans(m*n);
        int i = 0;
        bool up = true;
        
        while(row < m && col < n){
            if(up){
                while(row > 0 && col < n-1){
                   ans[i++] = mat[row][col];
                   row--;
                   col++;
                }
                ans[i++] = mat[row][col];
                if(col == n-1){
                    row++;
                }
                else
                    col++;
            }
            else{
                while(col > 0 && row < m-1){
                    ans[i++] = mat[row][col];
                    col--;
                    row++;
                }
                ans[i++] = mat[row][col];
                if(row == m-1){
                    col++;
                }
                else
                    row++;
            }
            
            up = !up;
        }

        return ans;
    }
};