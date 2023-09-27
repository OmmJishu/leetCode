class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] > b[1];
        });
        
        int prev = intervals[0][1];
        int cnt = 1;
        
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][1] <= prev){
                continue;
            }
            else{
                cnt++;
                prev = intervals[i][1];
            }
        }
        
        return cnt;
    }
};