class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>> mp;
        for(auto it : access_times){
            mp[it[0]].push_back(stoi(it[1]));
        }
        
        vector<string> res;
        for(auto &it : mp){
            if(it.second.size() < 3)
                continue;
            
            sort(it.second.begin(),it.second.end());
            vector<int> temp = it.second;
        
            bool meet = false;
            for(int i = 2; i<temp.size(); i++){
                if(temp[i] - temp[i-2] < 100){
                    meet = true;
                    break;
                }
            }
            if(meet == true)
                res.push_back(it.first);
        }
        
        return res;
    }
};