class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res, left, right;
        int first = newInterval[0], last = newInterval[1];
        
        for(auto it : intervals){
            if(it[1] < first)
                left.push_back(it);
            else if(it[0] > last)
                right.push_back(it);
            else{
                first = min(first,it[0]);
                last = max(last,it[1]);
            }
        }
        
        res.insert(res.end(),left.begin(),left.end());
        res.push_back({first,last});
        res.insert(res.end(),right.begin(),right.end());
        
        return res;
         
    }
};