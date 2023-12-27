class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<int,char>> stk;
        stk.push({neededTime[0],colors[0]});
        int time = 0;
        
        for(int i = 1; i<colors.size(); i++){
            if(!stk.empty() && colors[i] == stk.top().second){
                if(stk.top().first <= neededTime[i]){
                    time += stk.top().first;
                    stk.pop();
                    stk.push({neededTime[i],colors[i]});
                }
                else{
                    time += neededTime[i];
                }
            }
            else{
                stk.push({neededTime[i],colors[i]});
            }
        }
        
        return time;
    }
};