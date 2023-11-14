/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> mp;
        
        for (int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id].first = employees[i]->importance;
            mp[employees[i]->id].second = employees[i]->subordinates;
        }
        
        int res = 0;
        unordered_set<int> st;
        dfs(mp,id,res,st);
        
        return res;
    }
    
private:
    void dfs(unordered_map<int,pair<int,vector<int>>> &mp, int id, int &res, unordered_set<int> &st){
        
        res += mp[id].first;
        st.insert(id);
        
        for(auto it : mp[id].second){
            if(st.find(it) == st.end()){
                dfs(mp,it,res,st);
            }
        }
    }
};