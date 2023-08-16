class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        
        for(int i = 0; i<senders.size(); i++){
            istringstream np(messages[i]);
            string word;
            int j = 0;
            for(; np>>word;)
                j++;
            
            mp[senders[i]] += j;
        }
        
        vector<pair<int,string>> store;
        for(auto it : mp)
            store.push_back({it.second,it.first});
        
        sort(store.begin(),store.end(), [](const pair<int,string>& a, const pair<int,string>& b){
            if(a.first > b.first)
                return true;
            else if(a.first == b.first)
                return a.second > b.second;
            return false;
        });
        
        return store[0].second;
    }
};