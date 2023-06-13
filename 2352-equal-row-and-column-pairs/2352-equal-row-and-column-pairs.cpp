class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> row2cnt;
        for(int i=0;i<n;i++)
            row2cnt[ grid[i] ]++;
        
        int cnt = 0;
        
        for(int j=0;j<n;j++){
            vector<int> col(n);
            for(int i=0;i<n;i++)
                col[i] = grid[i][j];
            cnt = cnt + row2cnt[ col ];
        }

        return cnt;
    }
};

        // vector<vector<int>> store1,store2;
        // for(int i = 0; i<grid.size(); i++){
        //     vector<int> temp1,temp2;
        //     for(int j = 0; j<grid[0].size(); j++){
        //         temp1.push_back(grid[i][j]);
        //         temp2.push_back(grid[j][i]);
        //     }
        //     store1.push_back(temp1);
        //     store2.push_back(temp2);
        // }
        // int count = 0;
        // for(auto a : store1){
        //     for(auto b : store2)
        //         if(a == b)
        //             count++;
        // }
        // return count;
        