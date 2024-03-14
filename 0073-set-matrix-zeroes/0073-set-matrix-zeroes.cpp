class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        unordered_set<int> a;
        unordered_set<int> b;
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<column; j++){
                if(matrix[i][j] == 0){
                    a.insert(i);
                    b.insert(j);
                }
            }
        }
        
        for(auto it : a){
            for(int j = 0; j<column; j++){
                matrix[it][j] = 0;
            }
        }
        
        for(auto it : b){
            for(int j = 0; j<row; j++){
                matrix[j][it] = 0;
            }
        }
        
    }
};