class Solution {
private:    
    void dfs(int row, int col, vector<vector<int>>& grid, int &area, int index){
        area += 1;
        grid[row][col] = index;
        int n = grid.size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,area,index);
            }
        }
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int n = grid.size();
        int m = grid[0].size();
        int index = 2;
        
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,grid,area,index);
                    mp[index] = area;
                    index++;
                    res = max(res,area);
                }
            }
        }
        
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    int curr = 1;
                    
                    for(int k = 0; k<4; k++){
                        for(int l = 0; l<4; l++){
                            int nrow = i + delRow[l];
                            int ncol = j + delCol[l];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                            {
                                int idx = grid[nrow][ncol];
                                if(idx>1 && st.count(idx)==0){
                                    st.insert(idx);
                                    curr += mp[idx];
                                }
                            }
                        }
                    }
                    
                    res = max(res,curr);
                }
            }
        }
        
        return res;
    }
};