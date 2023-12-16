class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n == 1) return 1;
        
        queue<tuple<int,int,int>> q; // {distance, row, col}
        q.push(make_tuple(1, 0, 0));
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        
        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};
        
        while (!q.empty()) {
            int distance = get<0>(q.front());
            int row = get<1>(q.front());
            int col = get<2>(q.front());
            q.pop();
            
            for (int i = 0; i < 8; i++) { 
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && distance + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = distance + 1;
                    if (nrow == n-1 && ncol == n-1) {
                        return dist[nrow][ncol];
                    }
                    q.push(make_tuple(dist[nrow][ncol], nrow, ncol));
                }
            }
        }
        
        return -1;
    }
};