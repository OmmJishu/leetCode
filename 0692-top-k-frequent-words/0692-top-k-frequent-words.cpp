class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it : words)
            mp[it]++;
            
        vector<pair<int,string>> store;
        for(auto it : mp)
            store.push_back({it.second,it.first});
        
        sort(store.begin(),store.end(), [](const pair<int,string>& a, const pair<int,string>& b){
            if(a.first > b.first)
                return true;
            else if(a.first == b.first)
                return a.second < b.second;
            return false;
        });
        
        vector<string> res(k,"");
        for(int i = 0; i < k; i++)
            res[i] = store[i].second;
        
        return res;
    }
};