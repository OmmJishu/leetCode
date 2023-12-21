class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // creating Adjecency Matrix
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto it : edges){
            int i = it[0];
            int j = it[1];
            int wt = it[2];
            dist[i][j] = wt;
            dist[j][i] = wt;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        for(int via = 0; via<n; via++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][via]==1e9 || dist[via][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        
        int cnt = n, ans;
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    c++;
                }
            }
            
            if(c<=cnt){
                cnt = c;
                ans = i;
            }
        }
        
        return ans;
    }
};