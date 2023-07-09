class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,vector<int>> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        
        vector<int> temp;
        for(auto i = 'a'; i<='z'; i++){
            if(mp.find(i) != mp.end()){
                auto it = mp[i];
                temp.push_back(it[1] - it[0] -1);
            }
        }
        
        vector<int> arr;
        for(auto it : mp){
            int a = it.first-'a';
            arr.push_back(distance[a]);
        }
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != temp[i])
                return false;
        }
        
        return true;
    }
};