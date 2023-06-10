class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        
        int a = 1;
        
        int row = res.size();
        int column = res[0].size();
        
        int startRow = 0, lastRow = row-1, startCol = 0, lastCol = column-1;
        
        while(a <= n*n){
            for(int i = startRow; i<=startRow; i++){
                for(int j = startCol; j<=lastCol-1; j++){
                    if(a > n*n) break;
                    res[i][j] = a++;
                }
            }
            
            
            for(int i = lastCol; i<=lastCol; i++){
                for(int j = startRow; j<=lastRow-1; j++){
                    if(a > n*n) break;
                    res[j][i] = a++;
                }
            }
            startRow++;
            lastCol--;
            
            for(int i = lastRow; i<=lastRow; i++){
                for(int j = lastCol+1; j>=startCol; j--){
                    if(a > n*n) break;
                    res[i][j] = a++;
                }
            }
            
            for(int i = startCol; i<=startCol; i++){
                for(int j = lastRow-1; j>=startRow; j--){
                    if(a > n*n) break;
                    res[j][i] = a++;
                }
            }
            lastRow--;
            startCol++;
        }
        
        return res;
        
    }
};