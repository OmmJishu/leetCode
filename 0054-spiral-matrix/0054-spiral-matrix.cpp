class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int column = matrix[0].size();
        
        int startRow = 0, lastRow = row-1, startCol = 0, lastCol = column-1;
        
        while(res.size() < row*column){
            for(int i = startRow; i<=startRow; i++){
                for(int j = startCol; j<=lastCol-1; j++){
                    if(res.size() >= row*column) break;
                    res.push_back(matrix[i][j]);
                }
            }
            
            
            for(int i = lastCol; i<=lastCol; i++){
                for(int j = startRow; j<=lastRow-1; j++){
                    if(res.size() >= row*column) break;
                    res.push_back(matrix[j][i]);
                }
            }
            startRow++;
            lastCol--;
            
            for(int i = lastRow; i<=lastRow; i++){
                for(int j = lastCol+1; j>=startCol; j--){
                    if(res.size() >= row*column) break;
                    res.push_back(matrix[i][j]);
                }
            }
            
            for(int i = startCol; i<=startCol; i++){
                for(int j = lastRow-1; j>=startRow; j--){
                    if(res.size() >= row*column) break;
                    res.push_back(matrix[j][i]);
                }
            }
            lastRow--;
            startCol++;
        }
        return res;
    }
};