class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});   // {difference, {row, col}}
        
        vector<vector<int>> dist(row,vector<int>(col,1e9));
        dist[0][0] = 0;
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int ro = it.second.first;
            int cl = it.second.second;
            
            if(ro == row-1 && cl == col-1) return diff;
            
            for(int i = 0; i<4; i++){
                int nrow = ro + delRow[i];
                int ncol = cl + delCol[i];
                
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col){
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[ro][cl]));
                    
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        
        return 0;
    }
};