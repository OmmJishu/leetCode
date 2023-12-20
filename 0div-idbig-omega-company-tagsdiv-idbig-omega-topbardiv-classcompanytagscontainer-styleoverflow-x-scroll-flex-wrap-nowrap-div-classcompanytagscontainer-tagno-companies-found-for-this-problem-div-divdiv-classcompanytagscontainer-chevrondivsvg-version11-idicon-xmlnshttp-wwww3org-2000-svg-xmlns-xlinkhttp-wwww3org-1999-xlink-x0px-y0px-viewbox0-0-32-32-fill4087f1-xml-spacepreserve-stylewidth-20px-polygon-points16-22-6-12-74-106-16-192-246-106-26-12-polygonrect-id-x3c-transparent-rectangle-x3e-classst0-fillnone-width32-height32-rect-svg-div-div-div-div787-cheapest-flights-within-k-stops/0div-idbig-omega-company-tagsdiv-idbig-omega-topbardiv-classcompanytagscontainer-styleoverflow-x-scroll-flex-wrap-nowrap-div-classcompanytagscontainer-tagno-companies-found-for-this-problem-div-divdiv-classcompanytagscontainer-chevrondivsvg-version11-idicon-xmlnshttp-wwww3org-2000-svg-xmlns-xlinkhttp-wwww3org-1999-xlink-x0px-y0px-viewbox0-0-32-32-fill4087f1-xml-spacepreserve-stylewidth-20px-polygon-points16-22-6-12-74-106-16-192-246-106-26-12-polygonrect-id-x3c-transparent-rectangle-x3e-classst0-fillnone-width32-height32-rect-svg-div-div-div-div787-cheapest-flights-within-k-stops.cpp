class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            mp[u].push_back({v,cost});
        }
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        queue<tuple<int,int,int>> q;   // {stops, node, distance}
        q.push(make_tuple(0,src,0));

        int maxLimit = k+1;
        
        while(!q.empty()){
            int currStep = get<0>(q.front());
            int currNode = get<1>(q.front());
            int currCost = get<2>(q.front());
            q.pop();
            
            if(currStep == maxLimit) break;
            
            for(auto it : mp[currNode]){
                int adjNode = it.first;
                int adjCst = it.second;
                
                if(currCost + adjCst < dist[adjNode] && currStep <= maxLimit){
                    dist[adjNode] = currCost + adjCst;
                    q.push(make_tuple(currStep + 1, adjNode, dist[adjNode]));
                }
            }
        }
        
        return dist[dst] != 1e9 ? dist[dst] : -1;
    }
};