class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> row, col;
        unordered_map<int,pair<int,int>> number;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                row[i]++;
                col[j]++;
                number[mat[i][j]] = {i,j};
            }
        }

        for(int i = 0; i<arr.size(); i++){
            auto it = number[arr[i]];
            int r = it.first;
            int c = it.second;

            row[r]--;
            if(row[r] == 0) return i;
            col[c]--;
            if(col[c] == 0) return i;
        }

        return 0;
    }
};