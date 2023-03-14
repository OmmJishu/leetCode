class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> store;
        for(int i = 0; i<names.size(); i++) {
            store.push_back({heights[i], names[i]});
        }
        sort(store.begin(),store.end());

        for(int i = 0; i<names.size(); i++) {
            names[i] = store[i].second;
        }
        reverse(names.begin(),names.end());
        return names;
    }
};