class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,1e8);
        time[k] = 0;
        
        for(int i = 0; i<n; i++){
            for(auto it : times){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(time[u] != 1e8 && (time[u] + w < time[v]))
                    time[v] = time[u] + w;
            }
        }
        
        int maxtime = 0;
        for (int i = 1; i <= n; i++)
            maxtime = max(maxtime, time[i]);
        
        if(maxtime == 1e8)
            return -1;
        return maxtime;
    }
};