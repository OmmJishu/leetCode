class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it : arr)
            mp[it]++;
        
        vector<pair<int,int>> store;
        for(auto it : mp)
            store.push_back({it.second,it.first});
        
        sort(store.begin(),store.end());
        vector<int> res;
        
        for(auto it : store){
            while(it.first--)
                res.push_back(it.second);
        }
        store.clear();
        mp.clear();
        set<int> st(res.begin()+k,res.end());
        res.clear();
        return (int)st.size();
    }
};