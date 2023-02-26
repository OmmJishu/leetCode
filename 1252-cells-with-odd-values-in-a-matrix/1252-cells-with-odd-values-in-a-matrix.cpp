class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> store(m, vector<int> (n, 0));
        
        int row = indices.size();
        for(int i = 0; i<row; i++){
            int k = indices[i][0];
            for(int a = 0; a<store[k].size(); a++){
                store[k][a] += 1;
            }
                
            int l = indices[i][1];
            for(int b = 0; b<store.size(); b++){
                store[b][l] += 1;
            }
        }
        int count = 0;
        for(int i = 0; i<store.size(); i++){
            for(int j = 0; j<store[0].size(); j++){
                if(store[i][j] % 2 == 1)
                    count++;
            }
        }
        return count;
    }
};