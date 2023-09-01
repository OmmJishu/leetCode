class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col] > 0){
                    bfs(row,col,vis,grid);
                }
            }
        }
        
        return maxi == INT_MIN ? 0 : maxi;
    }
    
private:
    int maxi = INT_MIN;
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int curr = 0;
        curr += grid[row][col];
        
        while(!q.empty()){
            int ro = q.front().first;
            int cl = q.front().second;
            q.pop();
            
            // Traverse in neighbour and mark them visited if they exist in 4 direction
            
            if(ro-1 >= 0 && ro-1 < n && cl >= 0 && cl < m && grid[ro-1][cl] > 0 && !vis[ro-1][cl]){
                curr += grid[ro-1][cl];
                vis[ro-1][cl] = 1;
                q.push({ro-1,cl}); // ok up
            }
            
            if(ro >= 0 && ro < n && cl-1 >= 0 && cl-1 < m && grid[ro][cl-1] > 0 && !vis[ro][cl-1]){
                curr += grid[ro][cl-1];
                vis[ro][cl-1] = 1;
                q.push({ro,cl-1});  // ok left
            }
            
            if(ro+1 >= 0 && ro+1 < n && cl >= 0 && cl < m && grid[ro+1][cl] > 0 && !vis[ro+1][cl]){
                curr += grid[ro+1][cl];
                vis[ro+1][cl] = 1;
                q.push({ro+1,cl}); // ok low
            }
            
            if(ro >= 0 && ro < n && cl+1 >= 0 && cl+1 < m && grid[ro][cl+1] > 0 && !vis[ro][cl+1]){
                curr += grid[ro][cl+1];
                vis[ro][cl+1] = 1;
                q.push({ro,cl+1}); // ok right
            }
        }
        
        maxi = max(maxi,curr);
    }
};