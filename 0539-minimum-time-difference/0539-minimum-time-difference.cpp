class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp(timePoints.size(),0);
        int res = INT_MAX;
        
        for(int i = 0 ; i < timePoints.size() ; i ++)
            temp[i] = (timePoints[i][0]-'0')*600 +  (timePoints[i][1]-'0')*60 + (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');

        sort(temp.begin(),temp.end());
        temp.push_back(temp[0]+24*60); // for comparing first and last if day end time is closest to day star time
        
        for(int i = 1 ; i < temp.size() ; i ++){
            res = min(res,temp[i]-temp[i-1]);
        }
        
        return res;
    }
};