class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
       
        for(int i = 0; i<grid[0].size(); i++){
            for(int j = 0; j<grid.size(); j++){
                int temp = abs(grid[j][i]);
                int count = 0;
                if(temp == 0)
                    count = 1;
                while(temp){
                    temp = temp/10;
                    count++;
                }
                if(grid[j][i] < 0)
                    count++;
                res[i] = max(res[i],count);
            }
        }
        return res;
    }
};