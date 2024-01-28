class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> pref(m,vector<int>(n,0));
        
        // Generating prefix sum matrix
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int leftRow = i, leftCol = j-1;
                int upperRow = i-1, upperCol = j;
                int upperLeftRow = i-1, upperLeftCol = j-1;
                
                int currVal = matrix[i][j], leftVal = 0, upperVal = 0, upperLeftVal = 0;
                
                if(leftCol >= 0) leftVal = pref[leftRow][leftCol];
                if(upperRow >= 0) upperVal = pref[upperRow][upperCol];
                if(upperLeftRow>=0 && upperLeftCol>=0) 
                    upperLeftVal = pref[upperLeftRow][upperLeftCol];
                
                pref[i][j] = currVal + leftVal + upperVal - upperLeftVal;
            }
        }
        
        int cnt = 0;
        for(int r1 = 0; r1<m; r1++)
        {
            for(int r2 = r1; r2<m; r2++)
            {
                unordered_map<int,int> mp;
                mp[0] = 1;
                for(int c = 0; c<n; c++)
                {
                    int currSum = pref[r2][c] - (r1 > 0 ? pref[r1-1][c] : 0);
                    int diff = currSum - target;
                    cnt += mp[diff];
                    mp[currSum]++;
                }
            }
        }
        
        return cnt;
    }
};