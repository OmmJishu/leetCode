class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size()));
        
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                
                int startRow = i-k;
                int endRow = i+k;
                int startCol = j-k;
                int endCol = j+k;
                
                if(startRow < 0) startRow = 0;
                if(endRow >= mat.size()) endRow = mat.size()-1;
                if(startCol < 0) startCol = 0;
                if(endCol >= mat[0].size()) endCol = mat[0].size()-1;
                
                int sum = 0;
                for(int k = startRow; k <= endRow; k++) 
                    for(int l = startCol; l <= endCol; l++) 
                        sum += mat[k][l];
                
                res[i][j] = sum;
            }
        }
        return res;
    }
};