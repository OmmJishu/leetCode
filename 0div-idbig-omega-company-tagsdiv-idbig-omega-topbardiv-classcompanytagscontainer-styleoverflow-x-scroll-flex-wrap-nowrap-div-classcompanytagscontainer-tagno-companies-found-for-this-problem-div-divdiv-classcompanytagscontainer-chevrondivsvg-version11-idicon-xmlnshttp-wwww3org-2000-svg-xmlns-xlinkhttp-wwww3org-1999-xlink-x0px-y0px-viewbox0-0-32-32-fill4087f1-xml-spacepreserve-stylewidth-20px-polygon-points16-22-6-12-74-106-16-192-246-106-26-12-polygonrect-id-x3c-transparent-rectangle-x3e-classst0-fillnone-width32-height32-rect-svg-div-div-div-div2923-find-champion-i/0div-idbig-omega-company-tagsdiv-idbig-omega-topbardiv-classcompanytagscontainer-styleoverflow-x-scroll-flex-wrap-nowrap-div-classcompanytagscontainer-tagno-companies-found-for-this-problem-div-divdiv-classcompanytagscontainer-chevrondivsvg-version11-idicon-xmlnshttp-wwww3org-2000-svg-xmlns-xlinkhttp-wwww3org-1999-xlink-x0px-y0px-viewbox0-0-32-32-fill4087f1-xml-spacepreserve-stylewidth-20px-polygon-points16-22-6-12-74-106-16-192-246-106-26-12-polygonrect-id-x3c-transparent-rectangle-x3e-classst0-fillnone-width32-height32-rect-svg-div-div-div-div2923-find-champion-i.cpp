class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0;  j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    mp[i].push_back(j);
                }
            }
        }
        
        vector<bool> mark(grid.size(),true);
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