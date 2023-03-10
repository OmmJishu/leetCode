class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> res;
        res.push_back(1);
        for(int i = 1; i<=n; i++){
            res.push_back(4*i+res[i-1]);
        }
        return res[n-1];
    }
};