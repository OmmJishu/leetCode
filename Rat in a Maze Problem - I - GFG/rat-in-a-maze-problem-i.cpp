//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        int row = maze.size();
        int col = maze[0].size();
        if(maze[row-1][col-1] == 0 || maze[0][0]==0)
            return {"-1"};
            
        vector<string> res;
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        string way = "";
        dfs(maze,0,0,vis,res,way);
        
        return res;
    }
    
private:
    void dfs(vector<vector<int>> &maze, int row, int col, vector<vector<int>> &vis, vector<string> &res, string &way){
        vis[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int n = maze.size();
        int m = maze[0].size();
        
        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]==1 && vis[nrow][ncol]==0){
                string temp = way;
                if(i==0) temp += 'U';
                else if(i == 1) temp += 'R';
                else if(i == 2) temp += 'D';
                else temp += 'L';
            
                if(nrow==n-1 && ncol==m-1){
                    res.push_back(temp);
                }
                else{
                    dfs(maze,nrow,ncol,vis,res,temp);
                }
            }
        }
        
        vis[row][col] = 0;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends