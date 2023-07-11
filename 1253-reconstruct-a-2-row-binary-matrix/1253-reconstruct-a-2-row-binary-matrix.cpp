class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res(2,vector<int>(colsum.size(),0));
        
        for(int i = 0; i<colsum.size(); i++){
            if(colsum[i] == 2){
                res[0][i] = 1;
                res[1][i] = 1;
            }
            else if(colsum[i] == 0){
                res[0][i] = 0;
                res[1][i] = 0;
            }
        }
        
        int r1Sum = 0, r2Sum = 0;
        for(int i = 0; i<colsum.size(); i++){
            r1Sum += res[0][i];
            r2Sum += res[1][i];
        }
        
        int remr1 = upper - r1Sum, remr2 = lower-r2Sum;
        for(int i = 0; i<colsum.size(); i++){
            if(res[0][i] == 0 && remr1 > 0 && res[1][i] == 0 && colsum[i] == 1){
                res[0][i] = 1;
                remr1--;
            }
        }
        
        for(int i = 0; i<colsum.size(); i++){
            if(res[0][i] == 0 && remr2 > 0 && res[1][i] == 0 && colsum[i] == 1){
                res[1][i] = 1;
                remr2--;
            }
        }
        
        
        int r1S = 0, r2S = 0;
        for(int i = 0; i<colsum.size(); i++){
            r1S += res[0][i];
            r2S += res[1][i];
        }
        if(r1S != upper || r2S != lower)
            return {};
        
        
        
        for(int i = 0; i<colsum.size(); i++){
            if(res[0][i] + res[1][i] != colsum[i])
                return {};
        }
        
        
        return res;
    }
};