class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0 && n == 1)
            return 0;
        
        unordered_map<int,vector<int>> mp;
        
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
        }
        
        vector<bool> mark(n,true);
        for(auto it : mp){
            for(auto ele : it.second){
                mark[ele] = false;
            }
        }
        
        
        int idx, cnt = 0;
        for(int i = 0; i<mark.size(); i++){
            if(mark[i] == true){
                idx = i;
                cnt++;
            }
        }
        
        return cnt == 1 ? idx : -1;
    }
};