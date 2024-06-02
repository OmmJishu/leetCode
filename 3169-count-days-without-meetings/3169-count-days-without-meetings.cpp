class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> temp;
        temp.push_back(meetings[0]);
        
        for(int i = 1; i<meetings.size(); i++){
            if(temp.back().back() >= meetings[i][0]){
                temp.back().back() = max(temp.back().back(),meetings[i][1]);
            }
            else{
                temp.push_back(meetings[i]);
            }
        }
        
        for(auto it : temp)
            days -= (it[1]-it[0]+1);
        
        return days;
    }
};