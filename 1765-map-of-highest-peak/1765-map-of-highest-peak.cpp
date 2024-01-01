class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(isWater[i][j] == 1)
                    q.push({i,{j,0}});
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int ro = q.front().first;
            int cl = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            vis[ro][cl] = dist==0?0:vis[ro][cl];
            
            for(int i = 0; i<4; i++){
                int nrow = ro + delRow[i];
                int ncol = cl + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && isWater[nrow][ncol] == 0 && vis[nrow][ncol] == -1){
                    vis[nrow][ncol] = dist + 1;
                    q.push({nrow,{ncol,dist+1}});
                }
                else if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && isWater[nrow][ncol] == 0 && vis[nrow][ncol] != -1){
                    int mini = vis[nrow][ncol];
                    if(dist+1 < mini){
                        vis[nrow][ncol] = dist+1;
                        q.push({nrow,{ncol,dist+1}});
                    }
                }
            }
        }
        
        return vis;
    }
};