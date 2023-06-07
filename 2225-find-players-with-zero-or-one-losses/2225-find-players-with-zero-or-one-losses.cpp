class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> st;
        for(int i = 0; i<matches.size(); i++){
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
        }
        
        unordered_map<int,int> mp;
        for(int i = 0; i<matches.size(); i++){
            mp[matches[i][1]]++;
        }
        
        vector<int> temp1,temp2;
        vector<int> store(st.begin(),st.end());
        for(int i = 0; i<store.size(); i++){
            if(mp.find(store[i]) == mp.end())
                temp1.push_back(store[i]);
            if(mp.find(store[i]) != mp.end()){
                if(mp[store[i]] == 1)
                    temp2.push_back(store[i]);
            }
        }
        
        return {temp1,temp2};
    }
};