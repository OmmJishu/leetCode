class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> answer(k,0);
        unordered_map<int,set<int>> mp;
        
        for(auto it : logs){
            mp[it[0]].insert(it[1]);
        }
        
        unordered_map<int,int> mp2;
        for(auto it : mp){
            mp2[it.second.size()]++;
        }
        
        for(auto it : mp2){
            answer[it.first-1] = it.second;
        }
        
        return answer;
    }
};