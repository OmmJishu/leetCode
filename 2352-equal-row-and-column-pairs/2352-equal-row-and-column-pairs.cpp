class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> store1,store2;
        for(int i = 0; i<grid.size(); i++){
            vector<int> temp1,temp2;
            for(int j = 0; j<grid[0].size(); j++){
                temp1.push_back(grid[i][j]);
                temp2.push_back(grid[j][i]);
            }
            store1.push_back(temp1);
            store2.push_back(temp2);
        }
        int count = 0;
        for(auto a : store1){
            for(auto b : store2)
                if(a == b)
                    count++;
        }
        return count;
    }
};