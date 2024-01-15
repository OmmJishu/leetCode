class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winner, looser;
        for(auto it : matches){
            winner[it[0]]++;
            looser[it[1]]++;
        }
        
        vector<int> notLost, oneLost;
        for(auto it : winner){
            if(looser[it.first] == 0)
                notLost.push_back(it.first);
        }
        for(auto it : looser){
            if(it.second == 1)
                oneLost.push_back(it.first);
        }
        
        sort(begin(notLost),end(notLost));
        sort(begin(oneLost),end(oneLost));
        
        return {notLost,oneLost};
    }
};