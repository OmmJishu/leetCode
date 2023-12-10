class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> store;

        for(int i = 0; i<column; i++){
            vector<int> temp;
            for(int j = 0; j<row; j++){
                int tmp = matrix[j][i];
                temp.push_back(tmp);
            }
            store.push_back(temp);
        }
        return store;
    }
};