class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size();
        int c=img[0].size();
        vector<vector<int>> res(r,vector<int>(c,0));
        vector<pair<int,int>> valid = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                int sum = img[i][j];
                int temp=1;
                
                for(int k = 0; k<8; k++){
                    int nrow = i+valid[k].first;
                    int ncol = j+valid[k].second;
                    
                    if(nrow>=0 && nrow<r && ncol>=0 && ncol<c){
                        sum += img[nrow][ncol];
                        temp++;
                    }
                }
                
                res[i][j] = sum/temp;
            }
        }
        
        return res;
    }
};